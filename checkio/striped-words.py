import re
import string


VOWELS = "AEIOUY"
CONSONANTS = "BCDFGHJKLMNPQRSTVWXZ"


def clean(text):
    filter = string.punctuation + ' '
    filter = r'['+filter+']'
    text = re.split(filter, text)
    text = [w.upper() for w in text if w.isalpha() and len(w) > 1]

    return text


def checkio(text):
    text = clean(text)


    return 0

#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio("My name is ...") == 3, "All words are striped"
    assert checkio("Hello world") == 0, "No one"
    assert checkio("A quantity of striped words.") == 1, "Only of"
    assert checkio("Dog,cat,mouse,bird.Human.") == 3, "Dog, cat and human"
