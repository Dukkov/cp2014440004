import time
import random
from operation import Operation
from rubiks import Rubiks
from search import Node, astar_search

default = ['UUUUUUUUULLLFFFRRRBBBLLLFFFRRRBBBLLLFFFRRRBBBDDDDDDDDD']
goal = ['UUUUUUUUULLLFFFRRRBBBLLLFFFRRRBBBLLLFFFRRRBBBDDDDDDDDD']


def main():
    global default_cube
    global goal
    scrambled = scrambler(default, 3)
    cube = Rubiks(scrambled, goal)

    startTime = time.time()

    result = astar_search(cube)

    endTime = time.time()

    print('solution is', Node.solution(result))
    print('path is', Node.path(result))
    print('걸린 시간 :', endTime - startTime)


def scrambler(state, count):
    scramble = Operation()
    actions = ['L', 'Li', 'R', 'Ri', 'U', 'Ui', 'D', 'Di', 'F', 'Fi', 'B', 'Bi', 'M', 'Mi', 'E', 'Ei', 'S', 'Si']
    moves = " ".join((random.choice(actions) for i in range(count)))
    print(moves)
    result = scramble.sequence(moves, state)
    return result

if __name__ == '__main__':
    main()
