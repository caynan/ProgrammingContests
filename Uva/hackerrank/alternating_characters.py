#!/usr/bin/python3

def alternate(string):
    count = 0
    prev = ''
    for l in string:
        if l == prev:
            count += 1
        prev = l

    return count


if __name__ == '__main__':
    rep = int(input())

    for i in range(rep):
        string = input()
        print(alternate(string))
