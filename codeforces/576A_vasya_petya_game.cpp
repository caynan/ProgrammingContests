#include <iostream>
#include <iterator>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<bool> primes(n+1, true);

    primes[0] = primes[1] = false;
    for (auto i = 2; i <= n; ++i) {
        if (1ll * i * i <= n) {
            for (auto j = i * i; j <= n; j += i) {
                primes[j] = false;
            }
        }
    }

    vector<int> ans;
    int s;
    for (auto i = 0; i <= n; ++i) {
        if (primes[i]) {
            s = 1;
            while (s <= n / i) {
                s *= i;
                ans.push_back(s);
            }
        }
    }

    cout << ans.size() << endl;

    ostream_iterator<int> out_it(cout, " ");
    copy(ans.begin(), ans.end(), out_it);
    cout << endl;

    return 0;
}
