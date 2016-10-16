#include <iostream>
#include <string>


using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    for (auto& c : a) {
        c -= '0';
    }
    for (auto& c : b) {
        c -= '0';
    }

    int lenA = a.length(),
        lenB = b.length();

    int sum[lenB + 1][2];
    sum[0][0] = sum[0][1] = 0;

    for(auto i = 1; i <= lenB; ++i) {
        sum[i][0] = sum[i - 1][0];
        sum[i][1] = sum[i - 1][1];
        sum[i][ bool(b[i - 1]) ]++;
    }

    long long ans = 0;
    int temp = lenB - lenA + 1;
    for(auto i = 0; i < lenA; ++i) {
        ans += sum[temp+i][!a[i]];
        ans -= sum[i][!a[i]];
    }

    cout << ans << '\n';

    return 0;
}
