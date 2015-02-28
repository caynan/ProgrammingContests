def invert_convert(bit_num):
    bit_num = bin(int(bit_num))[2:]
    # complete with zero
    bit_num = '0'* (32 - len(bit_num)) + bit_num

    #flip bits
    bit_num = bit_num.replace('1', '2').replace('0', '1').replace('2', '0')
    return int(bit_num, 2)

if __name__ == '__main__':
    num_inputs = int(input())
    for i in range(num_inputs):
        bit_num = input().strip()
        print(invert_convert(bit_num))
