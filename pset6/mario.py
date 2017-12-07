from cs50 import *


def checkNb(nb):
    if nb <= 0 or nb >= 24:
        print("Usage : Please enter a value between 0 and 23 included.")
        return False
    return True


def drawPyramid(height):
    i = 0
    gap = "  "
    while i < height:
        c = 0
        space = height - i
        while c <= i:
            while space > 0:
                print(" ", end='')
                space -= 1
            print("#", end='')
            c += 1
        print(gap, end='')
        c = 0
        while c <= i:
            print("#", end='')
            c += 1
        i += 1
        print("")


def main():
    isValid = False
    while not isValid:
        print("Height : ", end='')
        height = get_int()
        isValid = checkNb(height)
    if height == 0:
        return 0
    drawPyramid(height)
    return 0


if __name__ == "__main__":
    main()
