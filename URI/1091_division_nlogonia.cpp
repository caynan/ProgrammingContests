# include <iostream>
# include <string>

using namespace std;

string region(int x, int y, int xCenter, int yCenter) {
    string answer;
    // Case point on the division point/line
    if (y == yCenter || x == xCenter) {
        answer = "divisa";
    }
    else {
        answer = "";
        // Check if on North or South of division
        if (y > yCenter) { answer.append("N"); }
        else { answer.append("S"); }
        // Check if on East or West of division
        if (x > xCenter){ answer.append("E"); }
        else { answer.append("O"); }
    }

    return answer;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int numQueries, xCenter, yCenter, x, y;

    while (cin >> numQueries && numQueries != 0) {
        cin >> xCenter >> yCenter;
        for (auto i = 0; i < numQueries; ++i) {
            cin >> x >> y;
            cout << region(x, y, xCenter, yCenter) << "\n";
        }
    }
}
