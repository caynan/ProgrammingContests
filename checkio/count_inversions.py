def sort_count(arr):
    l = len(arr)
    if l > 1:
        mid = l // 2
        l_half, l_count = sort_count(arr[:mid])
        r_half, r_count = sort_count(arr[mid:])
        sorted_arr, m_count = merge_count(l_half, r_half)
        return sorted_arr, (l_count + r_count + m_count)
    else:
        return arr, 0


def merge_count(l_half, r_half):
    count = 0
    merged = []

    while l_half and r_half:
        if l_half[0] <= r_half[0]:
            merged.append(l_half.pop(0))
        else:
            merged.append(r_half.pop(0))
            count += len(l_half)

    merged += l_half + r_half

    return merged, count

def count_inversion(arr):
    return sort_count(list(arr))[1]

if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert count_inversion((1, 2, 5, 3, 4, 7, 6)) == 3, "Example"
    assert count_inversion((0, 1, 2, 3)) == 0, "Sorted"
    assert count_inversion((99, -99)) == 1, "Two numbers"
    assert count_inversion((5, 3, 2, 1, 0)) == 10, "Reversed"
