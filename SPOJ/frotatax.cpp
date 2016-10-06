#include <iostream>

using namespace std;

int main() {
    float a, g, ra, rg;
    cin >> a >> g >> ra >> rg;

    // If the ratio of price over efficiency if bigger it means,
    // it has a better cost/efficiency ratio Duhh!
    auto answer = ( rg / g ) >= ( ra / a ) ? 'G' : 'A';
    cout << answer << "\n";

    return 0;
}
