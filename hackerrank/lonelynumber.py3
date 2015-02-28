#!/usr/bin/py
# Head ends here
def lonelyinteger(b):
    answer = list(b)
    answer = [x for x in answer if answer.count(x) == 1]
    return answer[0]


# Tail starts here
if __name__ == '__main__':
    a = int(input())
    b = map(int, input().strip().split(" "))
    print(lonelyinteger(b))
