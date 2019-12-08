from problem import Problem
from state import *
from operation import Operation


class Rubiks(Problem):
    def __init__(self, initial, goal=None):
        self.initial = initial
        self.goal = goal

    def actions(self, state):
        return ['L', 'Li', 'R', 'Ri', 'U', 'Ui', 'D', 'Di', 'F', 'Fi', 'B', 'Bi', 'M', 'Mi', 'E', 'Ei', 'S', 'Si']

    def result(self, state, action):
        rotator = Operation()
        next_state = rotator.rotate(action, state)
        return next_state

    def is_goal_state(self, state):
        cube = State(state)
        def check(colors):
            assert len(colors) == 9
            return all(c == colors[0] for c in colors)  # face의 colors가 모두 일치하면 true
        return (check([piece.colors[2] for piece in cube.findFace(FRONT)]) and  # front의 모든 piece z방향 color를 check
                check([piece.colors[2] for piece in cube.findFace(BACK)]) and
                check([piece.colors[1] for piece in cube.findFace(UP)]) and
                check([piece.colors[1] for piece in cube.findFace(DOWN)]) and
                check([piece.colors[0] for piece in cube.findFace(LEFT)]) and
                check([piece.colors[0] for piece in cube.findFace(RIGHT)]))

    def mis_placed(self, node):  # misplaced cibie heuristic
        cube = State(node.state)

        def edge_check(colors):
            assert len(colors) == 9
            miss = 0
            if (colors[0] != colors[1]):
                miss += 1
            if (colors[0] != colors[2]):
                miss += 1
            if (colors[0] != colors[3]):
                miss += 1
            if (colors[0] != colors[4]):
                miss += 1
            assert miss < 5
            return miss

        def mis_edge():  # 각 face에 대해 misplaced edge piece의 수를 계산하고 최댓값을 return
            return max(edge_check([piece.colors[2] for piece in cube.findFace(FRONT)]),
                       edge_check([piece.colors[2] for piece in cube.findFace(BACK)]),
                       edge_check([piece.colors[1] for piece in cube.findFace(UP)]),
                       edge_check([piece.colors[1] for piece in cube.findFace(DOWN)]),
                       edge_check([piece.colors[0] for piece in cube.findFace(LEFT)]),
                       edge_check([piece.colors[0] for piece in cube.findFace(RIGHT)]))

        def corner_check(colors):
            assert len(colors) == 9
            miss = 0
            if (colors[5] != colors[1] and colors[5] != colors[3]):
                miss += 1
            if (colors[6] != colors[1] and colors[6] != colors[4]):
                miss += 1
            if (colors[7] != colors[2] and colors[7] != colors[3]):
                miss += 1
            if (colors[8] != colors[2] and colors[8] != colors[4]):
                miss += 1
            assert miss < 5
            return miss

        def mis_corner():  # 각 face에 대해 misplaced corner piece의 수를 계산하고 최댓값을 return
            return max(corner_check([piece.colors[2] for piece in cube.findFace(FRONT)]),
                       corner_check([piece.colors[2] for piece in cube.findFace(BACK)]),
                       corner_check([piece.colors[1] for piece in cube.findFace(UP)]),
                       corner_check([piece.colors[1] for piece in cube.findFace(DOWN)]),
                       corner_check([piece.colors[0] for piece in cube.findFace(LEFT)]),
                       corner_check([piece.colors[0] for piece in cube.findFace(RIGHT)]))

        def mis_edge_corner():  # 각 face에 대해 misplaced corner, edge piece의 수를 더하고 최댓값을 return
            return max(corner_check([piece.colors[2] for piece in cube.findFace(FRONT)])
                       + edge_check([piece.colors[2] for piece in cube.findFace(FRONT)]),
                       corner_check([piece.colors[2] for piece in cube.findFace(BACK)])
                       + edge_check([piece.colors[2] for piece in cube.findFace(BACK)]),
                       corner_check([piece.colors[1] for piece in cube.findFace(UP)])
                       + edge_check([piece.colors[1] for piece in cube.findFace(UP)]),
                       corner_check([piece.colors[1] for piece in cube.findFace(DOWN)])
                       + edge_check([piece.colors[1] for piece in cube.findFace(DOWN)]),
                       corner_check([piece.colors[0] for piece in cube.findFace(LEFT)])
                       + edge_check([piece.colors[0] for piece in cube.findFace(LEFT)]),
                       corner_check([piece.colors[0] for piece in cube.findFace(RIGHT)])
                       + edge_check([piece.colors[0] for piece in cube.findFace(RIGHT)]))

        h1 = mis_edge()
        h2 = mis_corner()
        h3 = mis_edge_corner()
        #result = h1
        #result = h2
        result = h3
        return result

    def manhattan(self, node):  # manhattan distance heuristic
        cube = State(node.state)

        def distance(default, other, flag, plane=None):
            if (flag == 'c'):
                dist = [(default.pos - other.pos).count(0) for idx, other in enumerate(other)]   # 7. 5번 코너 piece와 c의 코너 piece들의 좌표차를 계산. 결과 좌표의 0이 2개이면 1 반환
                if 2 in dist:
                    return 1
                elif 1 in dist:
                    return 2
                else:
                    return 3
            elif (flag == 'e'):
                dist = [(default.pos - other.pos).count(0) for idx, other in enumerate(other)]
                if 2 in dist:
                    return 1
                elif 3 in dist:
                    return 3
                else:
                    return 2

        def par_distance(default, other, flag):
            if (flag == 'c'):
                dist = [(default.pos - other.pos).count(0) for idx, other in enumerate(other)]  # 7-1. 5번 코너 piece와 c의 코너 piece들의 좌표차를 계산. 결과 좌표의 0이 2개이면 1 반환
                if 1 in dist:
                    return 2
                else:
                    return 3
            elif (flag == 'e'):
                dist = [(default.pos - other.pos).count(0) for idx, other in enumerate(other)]
                if 1 in dist:
                    return 2
                elif 2 in dist:
                    return 2
                else:
                    return 3

        def corner_check(axis, cube, color):
            i = [idx for idx, val in enumerate(axis) if val != 0]
            k = [piece for piece in cube.findCorner(axis) if
                 piece.colors[i[0]] != color]  # 6. b의 색과 다른 corner piece를 저장하는 k
            return k

        def edge_check(axis, cube, color):
            i = [idx for idx, val in enumerate(axis) if val != 0]
            k = [piece for piece in cube.findEdge(axis) if
                 piece.colors[i[0]] != color]  # 6. b의 색과 다른 corner piece를 저장하는 k
            return k

        def corner_distance(colors, axis, cube):  # colors는 FRONT의 색상들 (0~9)
            assert len(colors) == 9
            frontface = colors[0]  # 1. frontface는 FRONT의 face 색상
            default = cube.findCorner(axis)  # 3. a는 FRONT의 corner piece 리스트. a[0]는 FRONT의 5번 piece.
            result = 0

            for i in range(4):
                if (colors[i+5] != frontface):  # 2. 5번 코너 piece가 face의 색과 다르다면
                    face = cube.find_piece(colors[i+5])  # 4. b는 FRONT의 5번 코너 piece와 색이 같은 face piece.
                    target = corner_check(face.pos, cube, color=next(item for item in face.colors if item is not None))  # 5. b의 face에 있는 piece중 b와 색이 다른 corner piece를 리턴하는 함수
                    if (face.pos + axis == Point(0,0,0)):
                        d = par_distance(default[i], target, 'c')
                        result += d
                    else:
                        d = distance(default[i], target, 'c')  # 8. min(7.)
                        result += d

            return result

        def edge_distance(colors, axis, cube):
            assert len(colors) == 9
            frontface = colors[0]  # 1. frontface는 FRONT의 face 색상
            default = cube.findEdge(axis)  # 3. default는 FRONT의 edge piece 리스트. default[0]는 FRONT의 1번 piece.
            result = 0

            for i in range(4):
                if (colors[i+1] != frontface):  # 2. 1번 edge piece가 face의 색과 다르다면
                    face = cube.find_piece(colors[i+1])  # 4. face는 FRONT의 1번 코너 piece와 색이 같은 face piece.
                    target = edge_check(face.pos, cube, color=next(item for item in face.colors if item is not None))  # 5. b의 face에 있는 piece중 b와 색이 다른 edge piece를 리턴하는 함수
                    plane = axis-face.pos
                    if (face.pos + axis == Point(0,0,0)):
                        d = par_distance(default[i], target, 'e')
                        result += d
                    else:
                        d = distance(default[i], target, 'e', plane)  # 8. min(7.)
                        result += d

            return result

        def man_corner():
            return sum([corner_distance([piece.colors[2] for piece in cube.findFace(FRONT)], FRONT, cube),  # 0. corner_distance에 FRONT의 z축 색상, axis, state 전달
                        corner_distance([piece.colors[2] for piece in cube.findFace(BACK)], BACK, cube),
                        corner_distance([piece.colors[1] for piece in cube.findFace(UP)], UP, cube),
                        corner_distance([piece.colors[1] for piece in cube.findFace(DOWN)], DOWN, cube),
                        corner_distance([piece.colors[0] for piece in cube.findFace(RIGHT)], RIGHT, cube),
                        corner_distance([piece.colors[0] for piece in cube.findFace(LEFT)], LEFT, cube)])

        def man_edge():
            return sum([edge_distance([piece.colors[2] for piece in cube.findFace(FRONT)], FRONT, cube),  # 0. edge_distance에 FRONT의 z축 색상, axis, state 전달
                        edge_distance([piece.colors[2] for piece in cube.findFace(BACK)], BACK, cube),
                        edge_distance([piece.colors[1] for piece in cube.findFace(UP)], UP, cube),
                        edge_distance([piece.colors[1] for piece in cube.findFace(DOWN)], DOWN, cube),
                        edge_distance([piece.colors[0] for piece in cube.findFace(RIGHT)], RIGHT, cube),
                        edge_distance([piece.colors[0] for piece in cube.findFace(LEFT)], LEFT, cube)])

        h3 = man_edge()
        h4 = man_corner()
        result = max((h3/4), (h4/4))
        return result




