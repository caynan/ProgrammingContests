import sys

days = int(input().split()[1])
instruments = list(map(int, input().split()))
pos = ''
count = 0
while days > 0:
    i = instruments.index(min(instruments))
    if days - instruments[i] >= 0:
        pos += (' %d ' % (i+1))
        days -= instruments[i]
        count += 1
        instruments[i] = sys.maxsize
    else:
        break

print (count)
print (pos.strip())
