#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    //    freopen("input.txt", "r", stdin);
    //    freopen("output.txt", "w", stdout);

    int numChangeRequest;
    string oldHandle, newHandle;
    map<string, string> handleMap, usedHandles;

    cin >> numChangeRequest;

    for(auto i = 0; i < numChangeRequest; ++i) {
        cin >> oldHandle >> newHandle;
        // Case first time user request to change handle
        if (!usedHandles.count(oldHandle)) {
            // keep track of all the chain of changes on handle AND if the
            // handle was or is being used.
            usedHandles[oldHandle] = oldHandle;
            usedHandles[newHandle] = oldHandle;

            // Actual mapping of old and new handle
            handleMap[oldHandle] = newHandle;
        }
        else {
            // new handle maps to old handle parent (previous handle) which
            // ends up being the first handle the user ever used.
            usedHandles[newHandle] = usedHandles[oldHandle];

            // Updated the mapping between first handle and the actual one.
            handleMap[usedHandles[oldHandle]] = newHandle;
        }
    }

    // Print results (mappings from handleMap)
    cout << handleMap.size() << "\n";
    for (auto const& mapping : handleMap) {
        cout << mapping.first << " " << mapping.second << "\n";
    }

    return 0;
}
