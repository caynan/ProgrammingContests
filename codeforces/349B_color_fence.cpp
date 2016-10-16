#include <iostream>

using namespace std;

const int NUM_DIGITS = 10;

int main() {
    long quantity[NUM_DIGITS] = {0};
    long occurrence[NUM_DIGITS] = {0};

    long paint, minQty = 1e6, minDigit = 0;

    cin >> paint;

    for (auto i = 1; i < NUM_DIGITS; ++i) {
        cin >> quantity[i];
        if (quantity[i] <= minQty) {
            minQty = quantity[i];
            minDigit = i;
        }
    }

    if (paint > minQty) {
        occurrence[minDigit] = paint / quantity[minDigit];
        paint %= quantity[minDigit];

        long currentDiff;
        int remainingDigit = 9;
        while (paint > 0 && remainingDigit > minDigit) {
            currentDiff = quantity[remainingDigit] - quantity[minDigit];
            occurrence[remainingDigit] += paint / currentDiff;
            occurrence[minDigit] -= paint / currentDiff;
            paint %= currentDiff;

            remainingDigit--;
        }

        // output
        for (auto digit = NUM_DIGITS - 1; digit >= minDigit; --digit) {
            for (auto i = 0; i < occurrence[digit]; ++i) {
                cout << digit;
            }
        }
        cout << endl;
    }
    else {
        cout << "-1" << endl;
    }

    return 0;
}
