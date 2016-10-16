#include <cstdio>

using namespace std;

typedef unsigned long long int llu;
typedef long long ll;
#define MAX 5000000
#define LMT 2237

unsigned flag[MAX >> 6];
ll prime[500000],divisor[MAX + 1], p, pp[MAX + 1];

#define ifc(n) (flag[n >> 6] &  (1 << ((n >> 1) & 31)))
#define isc(n) (flag[n >> 6] |= (1 << ((n >> 1) & 31)))

void sieve() {
    unsigned i, j, k;
    for(i=3; i < LMT; i+=2)
        if(!ifc(i))
            for(j=i*i, k=i<<1; j<MAX; j+=k)
                isc(j);
    prime[p++]=2;
    for(i=3;i<=MAX;i+=2)
    {
        if(!ifc(i))
            prime[p++]=i;
    }
}
int main() {
    ll i,j,t,A,B;

    sieve();

    for(i=2;i<=MAX;i++)
    {
        if(i==2||(!ifc(i)&&i%2!=0))
        divisor[i]=1;
        else
        for(j=0;prime[j]*prime[j]<=i&&j<p;j++)
        {
            if(i%prime[j]==0)
            {
                divisor[i]=1+divisor[i/prime[j]];
                break;
            }
        }
        pp[i]=pp[i-1]+divisor[i];
    }

    scanf("%I64d",&t);

    while(t--) {
        scanf("%I64d %I64d",&A,&B);
        printf("%I64d\n",pp[A]-pp[B]);
    }

    return 0;
}
