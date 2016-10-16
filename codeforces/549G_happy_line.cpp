#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int numResidents;
    cin >> numResidents;
    vector<int> numDollars;

    int temp;
    for (auto i = 0; i < numResidents; ++i) {
        cin >> temp;
        numDollars.push_back(temp + i);
    }

    sort(numDollars.begin(), numDollars.end());

    // check if impossible
    bool isPossible = true;
    for (auto i = 0; i < numResidents - 1; ++i) {
        // cout << numDollars[i] << " " << numDollars[i + 1] << endl;
        if (numDollars[i] == numDollars[i + 1]) {
            isPossible = false;
            break;
        }
    }

    if (isPossible) {
        for (auto i = 0; i < numResidents; ++i) {
            if (i != numResidents - 1) {
                cout << numDollars[i] - i << " ";
            } else {
                cout << numDollars[i] - i << endl;
            }
        }
    } else {
        cout << ":(" << endl;
    }



    return 0;
}
