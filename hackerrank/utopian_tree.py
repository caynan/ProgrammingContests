def utopian(cycles):
    # base case
    if cycles == 0:
        return 1
    # case is odd
    elif cycles % 2:
        return utopian(cycles - 1) * 2
    # case is even
    else:
        return utopian(cycles - 1) + 1

if __name__ == '__main__':
    t = int(input())
    for i in range(t):
        n = int(input())
        print(utopian(n))

