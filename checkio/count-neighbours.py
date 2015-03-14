from itertools import product


def neighbours(i, j, grid):
    neighbours = list(product(range(i-1, i+2), range(j-1, j+2)))
    neighbours.remove((i,j))
    l_i = len(grid)
    l_j = len(grid[0])
    neighbours = [(x, y) for (x, y) in neighbours if 0 <= x < l_i and
                  0 <= y < l_j]

    return neighbours


def count_neighbours(grid, row, col):
    sum = 0
    for i, j in neighbours(row, col, grid):
        sum += grid[i][j]

    return sum


if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert count_neighbours(((1, 0, 0, 1, 0),
                             (0, 1, 0, 0, 0),
                             (0, 0, 1, 0, 1),
                             (1, 0, 0, 0, 0),
                             (0, 0, 1, 0, 0),), 1, 2) == 3, "1st example"
    assert count_neighbours(((1, 0, 0, 1, 0),
                             (0, 1, 0, 0, 0),
                             (0, 0, 1, 0, 1),
                             (1, 0, 0, 0, 0),
                             (0, 0, 1, 0, 0),), 0, 0) == 1, "2nd example"
    assert count_neighbours(((1, 1, 1),
                             (1, 1, 1),
                             (1, 1, 1),), 0, 2) == 3, "Dense corner"
    assert count_neighbours(((0, 0, 0),
                             (0, 1, 0),
                             (0, 0, 0),), 1, 1) == 0, "Single"
