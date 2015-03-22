def checkio(data):
    # zip(*data) -> transpose of data, but return a list of tuples.
    # map(...) -> transform the previous list into a list of lists as expected
    # list(map(...)) -> get a list from the map iterable object
    return list(map(list,zip(*data)))
