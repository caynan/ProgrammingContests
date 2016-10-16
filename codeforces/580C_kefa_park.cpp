#include <iostream>
#include <vector>

using namespace std;

const int MAX_VALUE = 100005;

bool hasCat[MAX_VALUE];
vector<int> adjNodes[MAX_VALUE];

int countLeafs(int node, int previousNode, int seenCats, int maxCatsAllowed) {
    // case for consecutive cats
    if (hasCat[node]) {
        seenCats++;
    } else {
        seenCats = 0;
    }
    // cout << previousNode << " -> " << node << " seencats: " << seenCats << endl;
    // case when we have more cats on the path than the allowed.
    if (seenCats > maxCatsAllowed) {
        return 0;
    }
    // case we're in a leaf, we only have one edge to our parent.
    else if (node != 1 && adjNodes[node].size() == 1) {
        return 1;
    }
    // recursive call on all child nodes.
    else {
        int numRestaurants = 0;
        for (const auto& n : adjNodes[node]) {
            // ignore edge from our parent (we came from there duhh!)
            if (n != previousNode) {
                numRestaurants += countLeafs(n, node, seenCats, maxCatsAllowed);
            }
        }
        return numRestaurants;
    }
}

int main() {
    int numNodes, numCats;
    cin >> numNodes >> numCats;

    for (auto i = 1; i <= numNodes; ++i) {
        cin >> hasCat[i];
    }

    int nodeA, nodeB;
    for (auto i = 1; i < numNodes; ++i) {
        cin >> nodeA >> nodeB;
        adjNodes[nodeA].push_back(nodeB);
        adjNodes[nodeB].push_back(nodeA);
    }

    int numRestaurants = countLeafs(1, -1, 0, numCats);

    cout << numRestaurants << endl;
    return 0;
}
