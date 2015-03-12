import string


def checkio(data):
    length = len(data)
    data = set(data)
    contains_lower = not data.isdisjoint(set(string.ascii_lowercase))
    contains_upper = not data.isdisjoint(set(string.ascii_uppercase))
    contains_digit = not data.isdisjoint(set(string.digits))

    if length >= 10 and contains_lower and contains_upper and contains_digit:
        return True
    else:
        return False


#Some hints
#Just check all conditions


if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert checkio('A1213pokl') == False, "1st example"
    assert checkio('bAse730onE4') == True, "2nd example"
    assert checkio('asasasasasasasaas') == False, "3rd example"
    assert checkio('QWERTYqwerty') == False, "4th example"
    assert checkio('123456123456') == False, "5th example"
    assert checkio('QwErTy911poqqqq') == True, "6th example"
