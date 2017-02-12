def count_decoding(string):
    string_len = len(string)
    if string_len == 0 or string_len == 1:
        return 1

    count = 0
    if string[-1] > '0':
        count = count_decoding(string[:-1])

    if string[-2] < '2' or string[-2] == '2' and string[-1] < '7':
        count += count_decoding(string[:-2])

    return count

def dp_count_decoding(string):
    str_len = len(string)
    count = [0] * (str_len+1)
    count[0] = count[1] = 1

    for i in range(2, str_len+1):
        if string[i-1] > '0':
            count[i] = count[i-1]
        if string[i-2] < '2' or (string[i-2] == '2' and string[i-1] < '7'):
            count[i] += count[i-2]

    return count[str_len]

if __name__ == "__main__":
    print("1220123: ", count_decoding("1220123"))
    print("999: ", dp_count_decoding("999"))
    # print("12: ",  count_decoding("12"))
    # print("121: ",  count_decoding("121"))
