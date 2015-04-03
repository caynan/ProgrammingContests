def isTautogram(words):
    firsts = set(word[0].lower() for word in words)

    return len(firsts) == 1


if __name__ == '__main__':
    words = raw_input().split()
    while words != ['*']:
        if isTautogram(words):
            print 'Y'
        else:
            print 'N'
        words = raw_input().split()


