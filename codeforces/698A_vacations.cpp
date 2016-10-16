#include <iostream>

using namespace std;

int rest = 0;
int previousGym = 0;
int previousContest = 0;

void goRest() {
    previousGym = 0;
    previousContest = 0;
    rest++;
}

void goGym() {
    previousGym = 1;
    previousContest = 0;
}

void goContest() {
    previousGym = 0;
    previousContest = 1;
}

void goEither() {
    previousGym = 0;
    previousContest = 0;
}

int main() {
    int numDays;
    cin >> numDays;

    int type;
    for(int i = 0; i < numDays; i++) {
        cin >> type;

        if(type == 0) {
            goRest();
        }
        else if(type == 1) {
            if(previousContest == 0)
                goContest();
            else
                goRest();
        }
        else if(type == 2) {
            if(previousGym == 0)
                goGym();
            else
                goRest();
        }
        else if(type == 3) {
            if(previousGym == 1 && previousContest == 0) {
                goContest();
            }
            else if(previousGym == 0 && previousContest == 1) {
                goGym();
            }
            else
                goEither();
        }
    }

    cout << rest << endl;
    return 0;
}
