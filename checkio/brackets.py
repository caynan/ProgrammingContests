def checkio(expression):
    stack = []
    for c in expression:
        if c in '({[':
            stack.append(c)
        elif c in ')}]':
            # case stack is empty and receive an ending bracket
            if not stack:
                return False    
            # check oppening and closing brackets
            top = stack.pop()
            if top == '(' and c != ')':
                return False
            elif top == '{' and c != '}':
                return False
            elif top == '[' and c != ']':
                return False

    # case stack not empty
    if stack:
        return False
    else:
        return True


#These "asserts" using only for self-checking and not necessary for auto-testing
if __name__ == '__main__':
    assert checkio("((5+3)*2+1)") == True, "Simple"
    assert checkio("{[(3+1)+2]+}") == True, "Different types"
    assert checkio("(3+{1-1)}") == False, ") is alone inside {}"
    assert checkio("[1+1]+(2*2)-{3/3}") == True, "Different operators"
    assert checkio("(({[(((1)-2)+3)-3]/3}-3)") == False, "One is redundant"
    assert checkio("2+3") == True, "No brackets, no problem"
