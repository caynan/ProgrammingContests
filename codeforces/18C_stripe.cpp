#include <iostream>

using namespace std;

int const MAX_NUM = 100010;

int main() {
    int n, nums[MAX_NUM], sum[MAX_NUM];

    // Get values
    while (cin >> n) {
        for (auto i = 1; i <= n; ++i) {
            cin >> nums[i];
            sum[i] = sum[i - 1] + nums[i];
        }

        int ans = 0;
        for (auto i = 1; i < n; ++i) {
            if (sum[n] == sum[i] * 2) ans++;
        }

        // output
        cout << ans << endl;
    }

    return 0;
}
