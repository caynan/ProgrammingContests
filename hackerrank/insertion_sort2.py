def insertion_sort(ar):
    for i, val in enumerate(ar):
        if i == 0:
            continue

        index = i
        while index > 0 and ar[index - 1] > val:
            ar[index] = ar[index - 1]
            index -= 1
        ar[index] = val
        print_list(ar)


def print_list(aList):
    aList = map(str, aList)
    print(' '.join(aList))


if __name__ == '__main__':
    s = input()
    ar = input().split()
    ar = list(map(int, ar))

    insertion_sort(ar)
