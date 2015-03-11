from string import punctuation


def check_pangram(text):
    # preprocess the string
    filter = punctuation + ' '
    text = ''.join(c.lower() for c in text if c not in filter)

    # count letters
    alphabet = set(text)

    return len(alphabet) == 26  # there are 26 letters in the alphabet


if __name__ == '__main__':
    # These "asserts" using only for self-checking and not necessary for auto-testing
    assert check_pangram("The quick brown fox jumps over the lazy dog."), "brown fox"
    assert not check_pangram("ABCDEF"), "ABC"
    assert check_pangram("Bored? Craving a pub quiz fix? Why, just come to the Royal Oak!"), "Bored?"
