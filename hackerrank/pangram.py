def isPangram(string):
    s = set()
    for word in string:
        s.union(word.lower())

        if len(s) >= 26:
            return "pangram"
    else:
        return "not pangram"

if __name__ == "__main__":
    string = input()

    print(isPangram(string))
