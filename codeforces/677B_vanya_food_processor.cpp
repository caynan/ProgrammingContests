#include <iostream>

using namespace std;

typedef long long lld;

int main() {
    int n, h, k, s = 0;
    lld ans = 0;
    cin >> n >> h >> k;

    int x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (s + x <= h) {
            s += x;
        } else {
            s = x;
            ans++;
        }

        ans += s / k;
        s %= k;
    }

    // output
    if(s) ans++;

    cout << ans << endl;

    return 0;
}
