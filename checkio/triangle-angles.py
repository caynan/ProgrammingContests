from math import acos, degrees


def valid_triangle(a,b,c):
    return (a + b > c) and (a + c > b) and (b + c > a)


def law_cosine(side1, side2, opposite):
    angle = acos((side1 ** 2 + side2 ** 2 - opposite ** 2) / (2 * side1 * side2))

    return round(degrees(angle))


def checkio(a, b, c):
    angles = [0, 0, 0]
    # check validity
    if not valid_triangle(a, b, c):
        return angles

    # find angles using the law of cosines
    angles[0] = law_cosine(a, b, c)
    angles[1] = law_cosine(a, c, b)
    angles[2] = 180 - angles[0] - angles[1]

    # sort angles
    angles.sort()

    return angles


#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio(4, 4, 4) == [60, 60, 60], "All sides are equal"
    assert checkio(3, 4, 5) == [37, 53, 90], "Egyptian triangle"
    assert checkio(2, 2, 5) == [0, 0, 0], "It's can not be a triangle"
