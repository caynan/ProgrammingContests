#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    map<string, int> murderers;
    set<string> murdered;
    string assasin, victim;

    while (cin >> assasin >> victim) {
        // case our assasin is still alive
        if (!murdered.count(assasin)) {
            murderers[assasin] += 1;
        }
        // Add victim to set of murdered people.
        murdered.emplace(victim);
        // Remove victim from list of assasins (if it was an assasin in the first place)
        murderers.erase(victim);
    }

    cout << "HALL OF MURDERERS" << "\n";
    // print assasins (map is already in order.)
    for (auto obj : murderers) {
        cout << obj.first << " " << obj.second << "\n";
    }

    return 0;
}
