#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    int numContests, numStudents;
    int coeficient[3];
    unordered_map<int, bool> ranking;

    while (cin >> numContests >> numStudents) {
        for(auto i = 0; i < numContests; ++i) {
            cin >> coeficient[i];
        }

        // clean ranking
        ranking.clear();

        int pos;
        bool isValid = true;

        // simulate for each possible numContests possible :D

        // Case numContests == 1
        if (numContests == 1) {
            for (auto t1 = 1; t1 <= numStudents && isValid; ++t1) {
                pos = coeficient[0] * t1;
                // check if we already have a student on that rank
                if (!ranking[pos]) {
                    ranking[pos] = true;
                } else {
                    isValid = false;
                }
            }
        }
        // Case numContests == 2
        else if(numContests == 2) {
            for (auto t2 = 1; t2 <= numStudents && isValid; ++t2) {
                for (auto t1 = 1; t1 <= numStudents && isValid; ++t1) {
                    pos = coeficient[0] * t1 + coeficient[1] * t2;
                    // check if we already have a student on that rank
                    if (!ranking[pos]) {
                        ranking[pos] = true;
                    } else {
                        isValid = false;
                    }
                }
            }
        }
        // Case numContests == 3
        else {
            for (auto t3 = 0; t3 <= numStudents && isValid; ++t3) {
                for (auto t2 = 1; t2 <= numStudents && isValid; ++t2) {
                    for (auto t1 = 1; t1 <= numStudents && isValid; ++t1) {
                        pos = coeficient[0] * t1 +
                            coeficient[1] * t2 +
                            coeficient[2] * t3;
                        // check if we already have a student on that rank
                        if (!ranking[pos]) {
                            ranking[pos] = true;
                        } else {
                            isValid = false;
                        }
                    }
                }
            }
        }

        // output
        if (isValid) {
            cout << "Lucky Denis!" << endl;
        } else {
            cout << "Try again later, Denis..." << endl;
        }
    }

    return 0;
}
