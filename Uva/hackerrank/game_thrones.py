from itertools import permutations

def anagram(string):
    return list(map("".join, permutations(string)))

def isPalindrome(string):
    inv = string[::-1]
    return string == inv

if __name__ == '__main__':
    string = input()
    for s in anagram(string):
        if isPalindrome(s):
            print('YES')
            break
    else:
        print('NO')
