def checkio(data):
    if not data:
        return 0
    return data.pop() + checkio(data)
