#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int totalOffices, numVisitedOffices, temp;
    bool visitedOffices[1010] = { false };

    // Get total offices and the number of visited offices
    cin >> totalOffices >> numVisitedOffices;

    // Set all visited offices
    for (auto i = 0; i < numVisitedOffices; ++i) {
        cin >> temp;
        visitedOffices[temp] = true;
    }

    // Check if already visited
    for (auto i = 0; i < totalOffices; ++i) {
        cin >> temp;
        // We print 0(false) case we visited and 1 otherwise
        cout << !visitedOffices[temp] << "\n";

        // Set new visited office to true
        visitedOffices[temp] = true;
    }

    return 0;
}
