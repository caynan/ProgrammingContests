l=98690
s={x for x in range(2,l) if str(x)[::-1]==str(x)}-{c for i in range(2,l) for c in range(i*2,l,i)}
golf=lambda n:min(x for x in s if x>n)
