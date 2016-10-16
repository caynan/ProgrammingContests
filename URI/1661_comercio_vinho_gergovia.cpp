#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    int numCitizens;
    while (cin >> numCitizens && numCitizens) {
        vector<int> houses(numCitizens);
        // trick to add elements to a vector
        for(auto &house : houses) {
            cin >> house;
        }
        long long int acc = 0, ans = 0;
        for (auto i = 0; i < numCitizens; ++i) {
            acc += houses[i];
            ans += llabs(acc);
        }
        cout << ans << endl;
    }

    return 0;
}
