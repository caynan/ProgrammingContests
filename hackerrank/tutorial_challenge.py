def binary_search(ar, v):
    first, last = 0, len(ar) - 1

    while first <= last:
        mid = (first + last) // 2
        if ar[mid] == v:
            return mid
        elif ar[mid] > v:
            first = mid + 1
        else:
            last = mid - 1

if __name__ == '__main__':
    v = int(input())
    n = input()
    ar = input().split()
    ar = list(map(int, ar))  # convert to int

    print (binary_search(ar, v))
