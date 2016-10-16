#include <iostream>

using namespace std;

#define ll long long

const ll MOD = (1LL << 31) - 1;

ll modAndPow(ll exponent) {
    ll ans = 1, a = 3;

    while (exponent > 0) {
        if (exponent & 1) {
            ans = (ans * a) % MOD;
        }
        a = (a * a) % MOD;
        exponent >>= 1;
    }

    return ans;
}

int main () {

    ll N;
    cin >> N;
    cout << modAndPow(N) << endl;

    return 0;
}
