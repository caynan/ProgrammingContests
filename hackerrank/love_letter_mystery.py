#!/usr/bin/python3

def to_palindrome(string):
    inv_string = string[::-1]
    count = 0
    # Already a palindrome
    if string == inv_string:
        return count

    # We just compare the first half of each
    mid = len(string)//2

    for i in range(mid):
        count += abs(ord(string[i]) - ord(inv_string[i]))

    return count


if __name__ == '__main__':
    rep = int(input())
    for i in range(rep):
        string = input()
        print(to_palindrome(string))



