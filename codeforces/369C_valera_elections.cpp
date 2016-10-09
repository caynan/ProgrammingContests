#include <iostream>
#include <vector>
#include <unordered_map>
#include <utility>
#include <set>

using namespace std;

// Adjancecy list using unordered_map, by using a adjList dfs runs in O(V + E)
// in case you don't know, using adjMatrix makes dfs run in O(V^2).
unordered_map<int, vector<int> > adjList;
// set to keep track of districs with problematic roads.
vector<bool> problematicDistrict;
// save the number of roads the candidate will fix
vector<int> numFixedRoad;
// the set of visited nodes, so we don't need to visit them again
vector<bool> visited;

void dfs(int vertex) {
    // check if already visited, if not mark as visited.
    if (visited[vertex]) return;
    visited[vertex] = true;

    // if the vertex is a problematic one, mark that it fixes one road.
    if (problematicDistrict[vertex]) numFixedRoad[vertex] = 1;

    // go over each children of vertex
    for(auto i = 0; i < adjList[vertex].size(); ++i) {
        // cache child, to avoid accesing adjList and make it prettier :)
        auto child = adjList[vertex][i];
        // if we already visited children, ignore it.
        if (visited[child]) continue;
        dfs(child);
        // add number of roads that vertex children fixes.
        // see comment below to understand why we do this.
        numFixedRoad[vertex] += numFixedRoad[child];
    }
}

int main() {
    // The number of districs, and also the number of candidates
    int numDistricts;
    cin >> numDistricts;

    // resize all vectors to avoid segfault
    problematicDistrict.resize(numDistricts + 1);
    numFixedRoad.resize(numDistricts + 1);
    visited.resize(numDistricts + 1);

    // Get all the edges
    int districtA, districtB, roadType;
    for (auto i = 0; i < numDistricts - 1; ++i) {
        cin >> districtA >> districtB >> roadType;

        adjList[districtB].push_back(districtA);
        adjList[districtA].push_back(districtB);

        // we need to keep track os all roads with problems, we're adding
        // both A and B to problematic roads.
        if (roadType == 2) {
            problematicDistrict[districtA] = true;
            problematicDistrict[districtB] = true;
        }
    }

    // we're going to do a dfs starting on the root(1) to find all possible paths
    // to other districs
    dfs(1);

    vector<int> solutionCandidates;
    for (auto candidate = 1; candidate <= numDistricts; ++candidate) {
        // if a candidate has a repair rate of 1, it means that there is no
        // other child that will repair any roads. in case it's != than 1, it
        // means that we can choose a child that will eventualy go through it's
        // parent and fix the road. We're basically choosing the optimal candidates (nodes).
        if(numFixedRoad[candidate] == 1) {
            solutionCandidates.push_back(candidate);
        }
    }

    if (!solutionCandidates.empty()) {
        // get number of candidates.
        cout << solutionCandidates.size() << "\n";

        // we're using ostream_iterator with copy to print elements separated by space.
        ostream_iterator<int> out_it (cout, " "); // iterator for cout
        copy(solutionCandidates.begin(), solutionCandidates.end(), out_it);
        cout << "\n"; // new line after list.
    }

    return 0;
}
