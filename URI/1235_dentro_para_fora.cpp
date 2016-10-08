#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string insideOut(string line);

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    // get num of lines and ignore it, so we can use getline later w/o problems.
    int numLines;
    cin >> numLines;
    cin.ignore();

    string line;
    for (auto i = 0; i < numLines; ++i) {
        getline(cin, line);
        cout << insideOut(line) << "\n";
    }

    return 0;
}

string insideOut(string line) {

    //get element in the middle
    auto midIt = next(line.begin(), line.size()/2);
    reverse(line.begin(), midIt);
    // reverse first half
    reverse(midIt, line.end());

    return line;
}
