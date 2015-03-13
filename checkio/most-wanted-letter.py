import string
from collections import Counter


def checkio(text):
    # preprocessing
    filter = ' ' + string.punctuation + string.digits
    text = ''.join(c for c in text.lower() if c not in filter)
    c = dict(Counter(text))

    # Sorting
    items = list(c.items())
    items.sort()  # sort by letters
    items.sort(key=lambda v: -v[1])  # sort by values

    return items[0][0]  # get letter from first element


if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio("Hello World!") == "l", "Hello test"
    assert checkio("How do you do?") == "o", "O is most wanted"
    assert checkio("One") == "e", "All letter only once."
    assert checkio("Oops!") == "o", "Don't forget about lower case."
    assert checkio("AAaooo!!!!") == "a", "Only letters."
    assert checkio("abe") == "a", "The First."
    print("Start the long test")
    assert checkio("a" * 9000 + "b" * 1000) == "a", "Long."
    print("The local tests are done.")
