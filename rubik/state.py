import string
import textwrap
from maths import Point, Matrix

RIGHT = X_AXIS = Point(1, 0, 0)
LEFT           = Point(-1, 0, 0)
UP    = Y_AXIS = Point(0, 1, 0)
DOWN           = Point(0, -1, 0)
FRONT = Z_AXIS = Point(0, 0, 1)
BACK           = Point(0, 0, -1)

FACE = 'face'
EDGE = 'edge'
CORNER = 'corner'

ROT_XY_CW = Matrix(0, 1, 0,
                   -1, 0, 0,
                   0, 0, 1)
ROT_XY_CC = Matrix(0, -1, 0,
                   1, 0, 0,
                   0, 0, 1)
ROT_XZ_CW = Matrix(0, 0, -1,
                   0, 1, 0,
                   1, 0, 0)
ROT_XZ_CC = Matrix(0, 0, 1,
                   0, 1, 0,
                   -1, 0, 0)
ROT_YZ_CW = Matrix(1, 0, 0,
                   0, 0, 1,
                   0, -1, 0)
ROT_YZ_CC = Matrix(1, 0, 0,
                   0, 0, -1,
                   0, 1, 0)


class State:
    def __init__(self, cube_list):
        cube_str = "".join(cube_list)
        assert len(cube_str) == 54
        """piece들의 속성, 방향, 색상을 지정"""
        self.faces = (
            Piece(pos=RIGHT, colors=(cube_str[28], None, None)),
            Piece(pos=LEFT, colors=(cube_str[22], None, None)),
            Piece(pos=UP, colors=(None, cube_str[4], None)),
            Piece(pos=DOWN, colors=(None, cube_str[49], None)),
            Piece(pos=FRONT, colors=(None, None, cube_str[25])),
            Piece(pos=BACK, colors=(None, None, cube_str[31])))
        self.edges = (
            Piece(pos=RIGHT + UP, colors=(cube_str[16], cube_str[5], None)),
            Piece(pos=RIGHT + DOWN, colors=(cube_str[40], cube_str[50], None)),
            Piece(pos=RIGHT + FRONT, colors=(cube_str[27], None, cube_str[26])),
            Piece(pos=RIGHT + BACK, colors=(cube_str[29], None, cube_str[30])),
            Piece(pos=LEFT + UP, colors=(cube_str[10], cube_str[3], None)),
            Piece(pos=LEFT + DOWN, colors=(cube_str[34], cube_str[48], None)),
            Piece(pos=LEFT + FRONT, colors=(cube_str[23], None, cube_str[24])),
            Piece(pos=LEFT + BACK, colors=(cube_str[21], None, cube_str[32])),
            Piece(pos=UP + FRONT, colors=(None, cube_str[7], cube_str[13])),
            Piece(pos=UP + BACK, colors=(None, cube_str[1], cube_str[19])),
            Piece(pos=DOWN + FRONT, colors=(None, cube_str[46], cube_str[37])),
            Piece(pos=DOWN + BACK, colors=(None, cube_str[52], cube_str[43])),
        )
        self.corners = (
            Piece(pos=RIGHT + UP + FRONT, colors=(cube_str[15], cube_str[8], cube_str[14])),
            Piece(pos=RIGHT + UP + BACK, colors=(cube_str[17], cube_str[2], cube_str[18])),
            Piece(pos=RIGHT + DOWN + FRONT, colors=(cube_str[39], cube_str[47], cube_str[38])),
            Piece(pos=RIGHT + DOWN + BACK, colors=(cube_str[41], cube_str[53], cube_str[42])),
            Piece(pos=LEFT + UP + FRONT, colors=(cube_str[11], cube_str[6], cube_str[12])),
            Piece(pos=LEFT + UP + BACK, colors=(cube_str[9], cube_str[0], cube_str[20])),
            Piece(pos=LEFT + DOWN + FRONT, colors=(cube_str[35], cube_str[45], cube_str[36])),
            Piece(pos=LEFT + DOWN + BACK, colors=(cube_str[33], cube_str[51], cube_str[44])),
        )

        self.pieces = self.faces + self.edges + self.corners
        """pieces는 faces, edges, corners를 포함"""

    def create(self, c):
        self.faces = [Piece(pos=Point(p.pos), colors=p.colors) for p in c.faces]
        self.edges = [Piece(pos=Point(p.pos), colors=p.colors) for p in c.edges]
        self.corners = [Piece(pos=Point(p.pos), colors=p.colors) for p in c.corners]
        self.pieces = self.faces + self.edges + self.corners

    def findFace(self, axis):
        """입력받은 face의 모든 pieces를 반환"""
        assert axis.count(0) == 2
        return [p for p in self.pieces if p.pos.dot(axis) > 0]

    def findCorner(self, axis):
        assert axis.count(0) == 2
        return [p for p in self.pieces if p.pos.dot(axis) > 0 and p.pos.count(0) == 0]

    def findEdge(self, axis):
        assert axis.count(0) == 2
        return [p for p in self.pieces if p.pos.dot(axis) > 0 and p.pos.count(0) == 1]

    def findSlice(self, plane):
        """입력받은 plane의 모든 pieces를 반환"""
        assert plane.count(0) == 1
        i = next(i for i, x in enumerate(plane) if x == 0)
        return [p for p in self.pieces if p.pos[i] == 0]  # pos[i] == 0인 모든 piece 반환

    def _color_list(self):
        right = [p.colors[0] for p in sorted(self.findFace(RIGHT), key=lambda p: (-p.pos.y, -p.pos.z))]
        left  = [p.colors[0] for p in sorted(self.findFace(LEFT),  key=lambda p: (-p.pos.y, p.pos.z))]
        up    = [p.colors[1] for p in sorted(self.findFace(UP),    key=lambda p: (p.pos.z, p.pos.x))]
        down  = [p.colors[1] for p in sorted(self.findFace(DOWN),  key=lambda p: (-p.pos.z, p.pos.x))]
        front = [p.colors[2] for p in sorted(self.findFace(FRONT), key=lambda p: (-p.pos.y, p.pos.x))]
        back  = [p.colors[2] for p in sorted(self.findFace(BACK),  key=lambda p: (-p.pos.y, -p.pos.x))]

        return (up + left[0:3] + front[0:3] + right[0:3] + back[0:3]
                   + left[3:6] + front[3:6] + right[3:6] + back[3:6]
                   + left[6:9] + front[6:9] + right[6:9] + back[6:9] + down)

    def flat_list(self):
        state_list = []
        state_list.append("".join(x for x in str(self) if x not in string.whitespace))
        return state_list

    def find_piece(self, colors):  # face cubie 중에 colors와 같은 색을 가진 piece 반환
        for p in self.pieces:
            if(p.pos.count(0) == 2 and colors == next(item for item in p.colors if item is not None)):
                return p



    def __str__(self):
        template = ("    {0}{1}{2}\n"
                    "    {3}{4}{5}\n"
                    "    {6}{7}{8}\n"
                    "{9}{10}{11} {12}{13}{14} {15}{16}{17} {18}{19}{20}\n"
                    "{21}{22}{23} {24}{25}{26} {27}{28}{29} {30}{31}{32}\n"
                    "{33}{34}{35} {36}{37}{38} {39}{40}{41} {42}{43}{44}\n"
                    "    {45}{46}{47}\n"
                    "    {48}{49}{50}\n"
                    "    {51}{52}{53}")

        return "    " + textwrap.dedent(template).format(*self._color_list()).strip()


class Piece:
    def __init__(self, pos, colors):
        self.pos = pos
        self.colors = list(colors)
        self.setType()
        self.type = None

    def setType(self):
        if self.colors.count(None) == 2:
            self.type = FACE
        elif self.colors.count(None) == 1:
            self.type = EDGE
        elif self.colors.count(None) == 0:
            self.type = CORNER
        else:
            raise ValueError("colors 수 불일치")

    def rotate(self, matrix):
        """piece 위치를 입력된 matrix 기반으로 rotate"""
        before = self.pos
        self.pos = matrix * self.pos

        """color rotate"""
        rot = self.pos - before
        if not any(rot):
            return  # no change occurred
        if rot.count(0) == 2:
            rot += matrix * rot

        if rot.count(0) != 1:
            print("before:", before)
            print("self.pos:", self.pos)
            print("rot:", rot)
        assert rot.count(0) == 1

        i, j = (i for i, x in enumerate(rot) if x != 0)  # x!=0일때 인덱스 i를 반환해 i,j에 대입
        self.colors[i], self.colors[j] = self.colors[j], self.colors[i]  # i,j번째 color를 서로 바꿈
