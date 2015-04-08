def find_elements(l, M):
    for index, val in enumerate(l):
        c = M - val
        if c in l:
            indexes = [i for i, e in enumerate(l) if e == c and i != index]
            if indexes:
                return ' '.join(str(x+1) for x in sorted(indexes + [index]))


if __name__ == '__main__':
    T = int(input())
    for i in range(T):
        M = int(input())
        N = int(input())
        l = list(map(int, input().split()))

        print(find_elements(l, M))
