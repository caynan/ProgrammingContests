def multi_base_converter(val):
    if len(val) >= 2 and val[1] == 'x':
        print(int(val, 0))
    else:
        ans = hex(int(val))
        ans = ans[0:2] + ans[2:].upper()
        print(ans)


while True:
    num = raw_input()
    if num[0] == '-':
        break

    multi_base_converter(num)
