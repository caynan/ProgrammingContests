#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    long long ans = 0;
    int val = 1;
    for (auto i = 0; i <= 9; ++i) {
        if (N >= val) {
            ans += N - val + 1;
        }
        val *= 10;
    }

    cout << ans << endl;

    return 0;
}
