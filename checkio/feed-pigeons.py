def checkio(n, pigeon = 1, last = 0):
    if n <= last:
        return last
    if n <= pigeon:
        return n
        
    return checkio(n - pigeon, 2 * pigeon - last + 1, pigeon)
