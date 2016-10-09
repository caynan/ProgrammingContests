#include <iostream>
#include <queue>
#include <set>
#include <utility>

using namespace std;

int main() {
    int initialNum, finalNum;
    // we will store the result of operation and the `level` num of operations so far
    queue< pair<int, int> > results;

    // we create a set to keep track of seen values, to avoid calculating things twice.
    set<int> seenValues;

    cin >> initialNum >> finalNum;
    results.push(make_pair(initialNum, 0));

    // do operations and add them to our queue. We stop when we find our value
    // deep down, we're basically doing a BFS, while we add new nodes to the tree
    while(!results.empty() && results.front().first != finalNum) {
        // get top element and remove it from the queue results
        pair<int, int> valuePair = results.front();
        results.pop(); // remove element


        // check if we already seen this number, case yes skip it. this make things WAAYY faster!
        if(seenValues.count(valuePair.first)) continue;
        // add value to seenValues
        seenValues.insert(valuePair.first);

        // Do operations on given value and then add them back to the queue
        // Operação 1: N = N*2
        results.emplace( make_pair(valuePair.first * 2, valuePair.second + 1) );
        // Operação 2: N = N*3
        results.emplace( make_pair(valuePair.first * 3, valuePair.second + 1) );
        // Operação 3: N = N/2
        results.emplace( make_pair(valuePair.first / 2, valuePair.second + 1) );
        // Operação 4: N = N/3
        results.emplace( make_pair(valuePair.first / 3, valuePair.second + 1) );
        // Operação 5: N = N+7
        results.emplace( make_pair(valuePair.first + 7, valuePair.second + 1) );
        // Operação 6: N = N-7
        results.emplace( make_pair(valuePair.first - 7, valuePair.second + 1) );
    }

    if (!results.empty() && results.front().first == finalNum) {
        pair<int, int> valuePair = results.front();
        cout << valuePair.second << "\n";
    }

    return 0;
}
