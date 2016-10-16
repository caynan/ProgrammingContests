#include <iostream>

using namespace std;

int main() {
    int numPins, height;
    cin >> numPins >> height;

    int pins[numPins];
    // get pin's heights
    for (int i = 0; i < numPins; ++i) {
        cin >> pins[i];
    }

    // Greedy-ly get the number of operations per pin.
    int count = 0;
    for (int i = 0; i < numPins-1; ++i) {
        while(pins[i] != height) {
            // Update num of operations
            count++;

            if (pins[i] < height) {
                pins[i]++;
                pins[i + 1]++;
            }
            else {
                pins[i]--;
                pins[i + 1]--;
            }
        }
    }

    cout << count << endl;

    return 0;
}
