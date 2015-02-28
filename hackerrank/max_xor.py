#!/usr/bin/python3

def max_xor(l, r):
    q = l ^ r
    a = 1
    while q:
        q //= 2
        a <<= 1
    return a - 1

if __name__ == '__main__':
    l = int(input())
    r = int(input())
    print(max_xor(l, r))
