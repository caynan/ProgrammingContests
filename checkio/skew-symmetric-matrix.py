def checkio(matrix):
    neg = [tuple([x * -1 for x in y]) for y in matrix]
    trans = list(zip(*matrix))

    return neg == trans
