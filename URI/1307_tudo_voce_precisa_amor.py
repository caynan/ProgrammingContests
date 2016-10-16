def gcd(a, b):
    while True:
        if a == 0:
            return b
        b = b % a

        if b == 0:
             return a
        a = a % b

num_tests = int(input())
for test_num in range(1, num_tests+1):
    str1 = str(input())
    str2 = str(input())

    if gcd(int(str1, 2), int(str2, 2)) > 1:
        print ("Pair #{test_num}: All you need is love!".format(test_num=test_num))
    else:
        print ("Pair #{test_num}: Love is not all you need!".format(test_num=test_num))
