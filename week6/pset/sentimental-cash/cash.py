from cs50 import get_float


def get_pennies(dollars):
    pennies = int(dollars/1)
    return pennies


def get_nickels(dollars):
    nickels = int(dollars/5)
    return nickels


def get_dimes(dollars):
    dimes = int(dollars/10)
    return dimes


def get_quarters(dollars):
    quarters = int(dollars/25)
    return quarters


def main():
    while True:
        dollars = get_float("Change: ")
        if (dollars >= 0):
            break

    cents = int(dollars * 100)

    quarters = get_quarters(cents)
    cents -= quarters * 25

    dimes = get_dimes(cents)
    cents -= dimes * 10

    nickels = get_nickels(cents)
    cents -= nickels * 5

    pennies = get_pennies(cents)
    cents -= pennies * 1

    total = quarters + dimes + nickels + pennies

    print(total)
    print(quarters)
    print(dimes)
    print(nickels)
    print(pennies)


main()
