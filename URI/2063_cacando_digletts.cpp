#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (true) {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

int lcm(int a, int b) {
    int temp = gcd(a, b);

    return temp ? (a / temp * b) : 0;
}

int main() {
    int hole[110];
    int N, ans = 1;

    cin >> N;
    // populate all the paths
    for (auto i = 1; i <= N; ++i) {
        cin >> hole[i];
    }

    for (auto initialHole = 1; initialHole <= N; ++initialHole) {
        int pos = hole[initialHole]; // where our diglet start
        int t = 1; // we start couting from t = 1, since in t = 0 they're ducked on their initial holes.
        // we walk through all holes until we get to the initial hole
        while (pos != initialHole) {
            // increate the time `t`
            t++;
            // go to next hole after pos.
            pos = hole[pos];
        }
        // we update our lcm with the time `t` that takes this diglet to
        // come back to it's initial hole.
        ans = lcm(ans, t);
    }
    // output our answer
    cout << ans << "\n";

    return 0;
}
