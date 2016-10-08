# include <iostream>
# include <stack>

using namespace std;

void marshalCoaches(int N);

int main() {
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);

    int N;
    while (cin >> N && N) {
        marshalCoaches(N);
        cout << "\n";  //empty line between blocks
    }
}

void marshalCoaches(int N) {
    int coach;

    while (true) {
        stack<int> station;
        int lastIn = 0;

        // logic for each case
        for (int numReads = 0; numReads < N; numReads++) {
            cin >> coach;
            if (coach == 0) return;  // end of current block

            // We keep pushing the trains into the station until the top element is the one we're seeking for.
            while (lastIn < N && coach != lastIn) {
                if (!station.empty() && station.top() == coach) {
                    break;
                }
                station.push(++lastIn);
            }

            if (station.top() == coach) {
                station.pop();
            }
        }

        // print logic
        if (station.empty()) {
            cout << "Yes" << "\n";
        } else {
            cout << "No" << "\n";
        }
    }
}
