/*
user: caynanvls (http://uhunt.felix-halim.net/id/183008)

problem: 10924 - Prime Words
link: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1865
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

bool isPrime(int sum);
int sumLetterValues(string word);

int main(){
//	read;
//	write;

    int sum;
    string word;

    while(cin >> word){
        sum = sumLetterValues(word);
        if (isPrime(sum)) {
            pf("It is a prime word.\n");
        } else {
            pf("It is not a prime word.\n");
        }
    }
    
}

bool isPrime(int sum){
    bool isPrime = true;
    for ( int i = 2; i <= sqrt(sum); i++){
        if(sum % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

int sumLetterValues(string word){
    int sum = 0;
    char c;
    for(int i = 0; i < word.length(); i++){
        c = word[i];
        if(c >= 'a' && c <= 'z'){
            sum += (c - 'a') + 1;
        } else {
            sum += (c - 'A') + 27; 
        }
    }
    return sum;
}
