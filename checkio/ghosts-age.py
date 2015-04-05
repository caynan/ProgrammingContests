def isFibonacci(n):
    '''
        A number is Fibonacci if and only if one or both of (5 * n**2 + 4) or (5 * n**2 – 4) is a perfect square (Source: Wiki)
    '''
    f1 = (5 * (n**2) + 4) ** 0.5
    f2 = (5 * (n**2) - 4) ** 0.5

    return f1.is_integer() or f2.is_integer()


def checkio(opacity):
    age, current = 0, 10000
    while current != opacity:
        age += 1
        if isFibonacci(age):
            current -= age
        else:
            current += 1

    return age

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio(10000) == 0, "Newborn"
    assert checkio(9999) == 1, "1 year"
    assert checkio(9997) == 2, "2 years"
    assert checkio(9994) == 3, "3 years"
    assert checkio(9995) == 4, "4 years"
    assert checkio(9990) == 5, "5 years"
