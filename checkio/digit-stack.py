def digit_stack(commands):
    sum = 0
    stack = []

    # process stack
    for cmd in commands:
        if 'PUSH' in cmd:
            stack.append(int(cmd[-1]))
        elif 'PEEK' in cmd:
            try:
                sum += stack[-1]
            except IndexError:
                pass
        else:
            try:
                sum += stack.pop()
            except IndexError:
                pass

    return sum


if __name__ == '__main__':
    #These "asserts" using only for self-checking and not necessary for auto-testing
    assert digit_stack(["PUSH 3", "POP", "POP", "PUSH 4", "PEEK",
                        "PUSH 9", "PUSH 0", "PEEK", "POP", "PUSH 1", "PEEK"]) == 8, "Example"
    assert digit_stack(["POP", "POP"]) == 0, "pop, pop, zero"
    assert digit_stack(["PUSH 9", "PUSH 9", "POP"]) == 9, "Push the button"
    assert digit_stack([]) == 0, "Nothing"
