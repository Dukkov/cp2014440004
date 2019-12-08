from state import *


class Operation:
    def __init__(self):
        pass

    def rotFace(self, face, matrix, state):
        self.rotPieces(state.findFace(face), matrix)

    def rotSlice(self, plane, matrix, state):
        self.rotPieces(state.findSlice(plane), matrix)

    def rotPieces(self, pieces, matrix):  # 입력받은 face or slice의 piece들을 matrix 방향으로 회전
        for piece in pieces:
            piece.rotate(matrix)

    def rotate(self, action, state):
        c = State(state)
        if action == 'L':
            self.rotFace(LEFT, ROT_YZ_CC, c)
        elif action == 'Li':
            self.rotFace(LEFT, ROT_YZ_CW, c)
        elif action == 'R':
            self.rotFace(RIGHT, ROT_YZ_CW, c)
        elif action == 'Ri':
            self.rotFace(RIGHT, ROT_YZ_CC, c)
        elif action == 'U':
            self.rotFace(UP, ROT_XZ_CW, c)
        elif action == 'Ui':
            self.rotFace(UP, ROT_XZ_CC, c)
        elif action == 'D':
            self.rotFace(DOWN, ROT_XZ_CC, c)
        elif action == 'Di':
            self.rotFace(DOWN, ROT_XZ_CW, c)
        elif action == 'F':
            self.rotFace(FRONT, ROT_XY_CW, c)
        elif action == 'Fi':
            self.rotFace(FRONT, ROT_XY_CC, c)
        elif action == 'B':
            self.rotFace(BACK, ROT_XY_CC, c)
        elif action == 'Bi':
            self.rotFace(BACK, ROT_XY_CW, c)
        elif action == 'M':
            self.rotSlice(Y_AXIS + Z_AXIS, ROT_YZ_CC, c)
        elif action == 'Mi':
            self.rotSlice(Y_AXIS + Z_AXIS, ROT_YZ_CW, c)
        elif action == 'E':
            self.rotSlice(X_AXIS + Z_AXIS, ROT_XZ_CC, c)
        elif action == 'Ei':
            self.rotSlice(X_AXIS + Z_AXIS, ROT_XZ_CW, c)
        elif action == 'S':
            self.rotSlice(X_AXIS + Y_AXIS, ROT_XY_CW, c)
        elif action == 'Si':
            self.rotSlice(X_AXIS + Y_AXIS, ROT_XY_CC, c)
        a = c.flat_list()
        return a

    def sequence(self, move_str, state):
        moves = move_str.split()
        for move in moves:
            after = self.rotate(move, state)
            state = after
        return state

