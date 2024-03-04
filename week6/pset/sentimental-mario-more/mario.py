from cs50 import get_int

while True:
    height = get_int("Height: ")
    if height >= 1 and height <= 8:
        break

c = 1

while c <= height:
    r = 0
    spaces = height - c
    while spaces > 0:
        print(' ', end="")
        spaces -= 1
    while r < c:
        print("#", end="")
        r += 1
    print(" " * 2, end="")
    while r > 0:
        print("#", end="")
        r -= 1
    c += 1
    print()
