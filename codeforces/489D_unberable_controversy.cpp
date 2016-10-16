#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Get the number of intersections(vertices) and roads (edges)
    int numIntersections, numRoads;
    cin >> numIntersections >> numRoads;
    // initialize vectors with roads(edges) and the vector that registers the
    // adjacent vertices
    vector<vector<int> > roads(numIntersections + 1);
    vector<vector<bool> > adjList(numIntersections + 1,
        vector<bool>(numIntersections + 1, false));

    int vertexA, vertexB;
    for (auto intersection = 0; intersection < numRoads; ++intersection) {
        cin >> vertexA >> vertexB;
        roads[vertexA].emplace_back(vertexB);
        adjList[vertexA][vertexB] = true;
    }

    int numDamnRhombi = 0;
    for (auto origin = 1; origin <= numIntersections; ++origin) {
        for(auto destination = 1; destination <= numIntersections; ++destination) {
            if (origin == destination) continue;
            int numCommonNeighbors = 0;
            for (auto e = 0; e < roads[origin].size(); ++e) {
                // count the number of common neighbors between origin and
                // destination vertices.
                if (adjList[ roads[origin][e] ][destination]) {
                    numCommonNeighbors++;
                }
            }
            // add number of possible ways to go from origin to destination, using
            // combination, numCommonNeighbors CHOOSE 2;
            numDamnRhombi += numCommonNeighbors * (numCommonNeighbors - 1) / 2;
        }
    }

    cout << numDamnRhombi << endl;

    return 0;
}
