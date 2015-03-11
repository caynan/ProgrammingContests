def checkio(first, second):
    # preprocessing
    first = set(first.split(','))
    second = set(second.split(','))

    # in common
    intersec = first.intersection(second)

    return ','.join(e for e in sorted(intersec))


#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio("hello,world", "hello,earth") == "hello", "Hello"
    assert checkio("one,two,three", "four,five,six") == "", "Too different"
    assert checkio("one,two,three", "four,five,one,two,six,three") == "one,three,two", "1 2 3"
