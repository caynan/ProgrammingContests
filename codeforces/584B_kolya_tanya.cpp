#include <iostream>

using namespace std;

const int MOD = 1e9 + 7;

long long mod(int a, int b) {
    long long tmp = a % MOD, ans = 1;
    while (b) {
        if (b & 1) {
            ans = (ans * tmp) % MOD;
        }
        tmp = (tmp * tmp) % MOD;
        b >>= 1;
    }

    return ans;
}

int main () {
    int n;
    cin >> n;
    int ans = mod(27, n) - mod(7, n);
    if (ans < 0) {
        ans += MOD;
    }

    cout << ans << endl;

    return 0;
}
