def get_cordinates(pawns):
    pawn = set()
    for p in pawns:
        row = int(p[1]) - 1
        col = ord(p[0]) - 97
        pawn.add((row, col))
    return pawn


def safe_pawns(pawns):
    pawns = get_cordinates(pawns)

    count = 0
    for p in pawns:
        low_left  = (p[0] - 1, p[1] - 1)
        low_right = (p[0] - 1, p[1] + 1)

        if low_left in pawns or low_right in pawns:
            count += 1

    return count