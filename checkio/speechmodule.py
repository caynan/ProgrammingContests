FIRST_TEN = ["one", "two", "three", "four", "five", "six", "seven",
             "eight", "nine"]
SECOND_TEN = ["ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",
              "sixteen", "seventeen", "eighteen", "nineteen"]
OTHER_TENS = ["twenty", "thirty", "forty", "fifty", "sixty", "seventy",
              "eighty", "ninety"]
HUNDRED = "hundred"


def checkio(n):
    hundreds = int((n - (n % 100)) / 100)
    tens = int((n % 100 - (n % 10)) / 10)
    unities = int(n % 10)

    answer = ''

    if hundreds:
        answer += FIRST_TEN[hundreds - 1] + ' hundred '

    if tens > 1:  # 20 - 99
        answer += OTHER_TENS[tens - 2]
        if unities:
            answer += ' ' + FIRST_TEN[unities - 1]
    elif tens == 1:  # 10 - 19
        answer += SECOND_TEN[unities]
    elif unities:  # 0 - 9
        answer += FIRST_TEN[unities - 1]

    return answer.strip()
