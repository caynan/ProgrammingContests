#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int const MAX = 2000007;
int p, q,maxPrime[MAX], sum1[MAX], sum2[MAX];

void init () {
    memset ( maxPrime , -1 , sizeof ( maxPrime) );
    sum1[0] = sum1[1] = 0;
    for (auto i = 2 ; i < MAX ; i++) {
        if (~maxPrime[i]) {
            sum1[i] = sum1[i-1];
            continue;
        }
        sum1[i] = sum1[i-1] + 1;
        for (auto j = 2*i ; j < MAX ; j += i) {
            maxPrime[j] = i;
        }
    }

    sum2[0] = 0;
    int digit[15], cnt = 0;
    for ( auto i = 1; i < MAX ; i++ ){
        cnt = 0;
        int x = i;
        while ( x ) {
            digit[cnt++] = x % 10;
            x /= 10;
        }

        bool flag = true;
        for (auto j = 0; j < (cnt + 1) / 2; j++) {
            if (digit[j] != digit[cnt-1-j]) flag = false;
        }

        sum2[i] = sum2[i - 1];
        if ( flag ) sum2[i]++;
    }
}

int gcd(int a, int b) {
    while (true) {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int main () {
    // init pre computed numbers.
    init ();

    cin >> p >> q;

    int ans = -1;

    int d = gcd (p, q);
    p /= d , q /= d;
    for (auto i = MAX-1 ; i >= 1 ; --i)
        if ( q * sum1[i] <= p * sum2[i] ) {
            ans = i;
            break;
        }

    if ( ans == -1 ) {
        cout << "Palindromic tree is better than splay tree" << endl;
    } else {
        cout << ans << endl;
    }
}
