from cs50 import get_int

while True:
    size = get_int("What is the size of the piramid? ")
    if size > 0 and size <= 8:
        break

i = 1  # colunas

while i <= size:
    j = 0  # linhas
    spaces = size - i
    while spaces > 0:
        print(' ', end="")
        spaces -= 1
    while j < i:
        print('#', end="")
        j += 1
    print()
    i += 1
