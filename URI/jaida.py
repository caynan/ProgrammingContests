def sieve(n):
    """ Input n>=6, Returns a list of primes, 2 <= p < n """
    n, correction = n-n%6+6, 2-(n%6>1)
    sieve = [True] * (n/3)
    for i in xrange(1,int(n**0.5)/3+1):
      if sieve[i]:
        k=3*i+1|1
        sieve[      k*k/3      ::2*k] = [False] * ((n/6-k*k/6-1)/k+1)
        sieve[k*(k-2*(i&1)+4)/3::2*k] = [False] * ((n/6-k*(k-2*(i&1)+4)/6-1)/k+1)
    return [2,3] + [3*i+1|1 for i in xrange(1,n/3-correction) if sieve[i]]

primes = sieve(1000000)
nTests = int(raw_input())
for nt in xrange(nTests):
    n = int(raw_input())
    jaida_list = map(int, raw_input().split())

    jaida_list.sort()

    if jaida_list[0] != 1:
        print 0
    else:
        for p in primes:
            if p not in jaida_list:
                print p - 1
                break
