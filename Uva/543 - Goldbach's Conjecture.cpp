/*
user: caynanvls (http://uhunt.felix-halim.net/id/183008)

problem: 543 - Goldbach's Conjecture 
link: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=484
*/
 
# include <iostream>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <cmath>
# include <string>
# include <sstream>
# include <bitset>

# include <algorithm>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <utility>
# include <functional>
 
 
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define tr(cont, it) for(typeof(cont.begin()) it=cont.begin() ; it != cont.end() ; it++)
#define gi(a) sf("%d", &a)
#define gi2(a, b) sf("%d%d", &a, &b)
#define gi3(a, b, c) sf("%d%d%d", &a, &b, &c)
#define gi4(a, b, c, d) sf("%d%d%d%d", &a, &b, &c, &d)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)

using namespace std;
bitset<1000000> bs;
vector<int> primes;

void sieve(int upperBound);
bool isPrime(int num);

int main(){
//  read;
//	write;

    sieve(1000);
    
    int n;
    while(gi(n) == 1, n) {  //stops when n == 0
        int a, b;
        for(int i = 1; i < SZ(primes); i++){
            a = primes[i];
            b = n - a;
            if (isPrime(b)){
                pf("%d = %d + %d\n", n, a, b);
                break;
            }
        }
    }
}

void sieve(int upperBound){
    bs.set();
    bs[0] = bs[1] = 0;
    for(int i = 2; i <= upperBound; i++){
        if(bs[i]) {
            for(int j = i * i; j <= upperBound; j+= i){
                bs[j] = 0;
            }
            primes.push_back((int) i);
        }
    }
}

bool isPrime(int num){
    bool isPrime = true;
    for(int i = 0; i < SZ(primes); i++){
        if (primes[i] * primes[i] > num){
            break;
        }
        if (num % primes[i] == 0) {
            isPrime = false;
            break;
        }
    }

    return isPrime;
}
