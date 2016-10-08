#include <iostream>

using namespace std;

int numSteps(int height, int length) {
    int current, previous = height, ans = 0;
    for (auto i = 0; i < length; ++i) {
        cin >> current;
        // Our ans increase when we have to carve deaper in our block (current < previous).
        if (current < previous) {
            ans += previous - current;
        }
        // Update previous value
        previous = current;
    }

    return ans;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int height, length, ans;
    // We stop receiving cases when height and length == 0
    while(cin >> height >> length && (height + length)) {
        cout << numSteps(height, length) << "\n";
    }

    return 0;
}
