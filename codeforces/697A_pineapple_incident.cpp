#include <iostream>

using namespace std;

int main() {
    long long t, s, x;
    cin >> t >> s >> x;

    long long ans = 0, ret = x - t;
    if (ret < s) {
        if (ret == 0) {
            ans = 1;
        }
    }
    else {
        if (ret % s == 0 || ret % s == 1) {
            ans = 1;
        }
    }

    if (ans) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
