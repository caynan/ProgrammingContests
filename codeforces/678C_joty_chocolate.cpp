#include <iostream>

using namespace std;

typedef long long lld;

lld gcd(lld a, lld b) {
    while (true) {
        if (a == 0) return b;
        b %= a;
        if (b == 0) return a;
        a %= b;
    }
}

lld lcm(lld a, lld b) {
    int temp = gcd(a, b);

    return a / temp * b;
}

int main() {
    lld n, a, b, p, q;
    while (cin >> n >> a >> b >> p >> q) {
        lld sum = 0;
        // big crazy formula, you need paper and patiente to come up with this :D
        sum = (n / a) * p + (n / b) * q - min(p, q) * (n / lcm(a, b));

        cout << sum << endl;
    }
}
