if __name__ == '__main__':
    while True:
        try:
            val1, val2 = raw_input().split()
            print int(val1) ^ int(val2)
        except EOFError:
            break
