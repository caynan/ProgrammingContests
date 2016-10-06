def get_area(l_windows):
    # get tuples (begin, end) for each window
    # we sort them to make it easy to calculate
    l_windows =  sorted([(x, x+200) for x in l_windows])

    # in case last window end if less than total size
    if (l_windows[-1][1] < 600):
        hole = 600 - l_windows[-1][1]
    else:
        hole = 0

    last_pos = 0
    for e in l_windows:
        diff = e[0] - last_pos
        if diff > 0:
            hole += diff
        last_pos = e[1]

    return hole * 100

if __name__ == "__main__":
    l_windows = list(map(int, input().strip().split()))
    print(get_area(l_windows))
