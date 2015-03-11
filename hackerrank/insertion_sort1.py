def insertion(aList):
    val = aList[-1]
    for i, num in reversed(list(enumerate(aList[:-1]))):
        if num > val:
            aList[i + 1] = num
            print_list(aList)
        else:
            aList[i + 1] = val
            print_list(aList)
            break
    # case val is the new smallest element
    else:
        aList[0] = val
        print_list(aList)


def print_list(aList):
    to_print = map(str, aList)
    print(' '.join(to_print))


if __name__ == '__main__':
    s = input()
    ar = input().split()
    ar = list(map(int, ar))

    insertion(ar)

