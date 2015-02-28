def hasPalindrome(string):
    # len(string) even
    if len(string) % 2 == 0:
        temp = sum([string.count(s) % 2 for s in set(string)])
        return temp == 0
    else:
        temp = sum([string.count(s) % 2 for s in set(string)])
        return temp == 1


if __name__ == '__main__':
    str_input = input()
    if hasPalindrome(str_input):
        print('YES')
    else:
        print('NO')
