#include <iostream>
#include <cstring>

using namespace std;

int const MOD = 1e9 + 7;

int dp[100010], k;

int calcule(int x) {
    if (x - k < 0) {
        return dp[x] = 1;
    }
    if (dp[x] != -1) {
        return dp[x];
    }

    return dp[x] = (calcule(x - k) + calcule(x - 1)) % MOD;
}

int main() {
    memset(dp, -1, sizeof(dp));

    int t, a, b;
    cin >> t >> k;
    for (auto i = 0; i < 100010; ++i) {
        calcule(i);
    }

    for (auto i = 1; i < 100007; ++i) {
        dp[i] = (dp[i - 1] + dp[i]) % MOD;
    }

    for (auto i = 0; i < t; ++i) {
        cin >> a >> b;

        cout << (dp[b] - dp[a - 1] + MOD) % MOD << "\n";
    }
}
