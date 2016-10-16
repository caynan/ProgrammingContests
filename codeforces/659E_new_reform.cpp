#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_VALUE = 100005;

vector<int> adjCities[MAX_VALUE];
bool visited[MAX_VALUE];
int numConnectedRoads[MAX_VALUE];

bool hasCycle(int city) {
    queue<int> mQueue;
    // mark city as visited
    visited[city] = true;
    // add city to queue
    mQueue.push(city);
    // initialize the numCities(vertices) and numRoads(edges)
    int numCities = 1;
    int numRoads = numConnectedRoads[city];

    // go through all cities that we can reach from out original city
    int currentCity;
    while(!mQueue.empty()) {
        currentCity = mQueue.front(); mQueue.pop();
        for(const auto& c : adjCities[currentCity]) {
            if(!visited[c]) {
                visited[c] = true;
                numCities++;
                numRoads += numConnectedRoads[c];
                mQueue.push(c);
            }
        }
    }

    // We use the property that, a tree has n - 1 edges, where n is the number of
    // vertices, but since we have a reference to the same edge twice we multiply by 2.
    return numRoads != 2 * (numCities - 1);
}

int main() {
    int numCities, numRoads;
    cin >> numCities >> numRoads;

    // Add all the edges to our vector of adjCities and update the number of
    // roads connecte to our cities.
    int cityA, cityB;
    for (auto i = 0; i < numRoads; ++i) {
        cin >> cityA >> cityB;
        adjCities[cityA].push_back(cityB);
        adjCities[cityB].push_back(cityA);
        numConnectedRoads[cityA]++;
        numConnectedRoads[cityB]++;
    }

    // We will go over all cities, DFS style, to check if  we have cycles.
    // if we have a cycle, it means that we can have an inward road for all
    // cities on this graph; Case not, it means we have a tree, so we will
    // have only one city w/o an inward road to it (the root).
    int numSeparatedCities = 0;
    for (auto city = 1; city <= numCities; ++city) {
        if (!visited[city]) {
            numSeparatedCities += hasCycle(city) ? 0 : 1;
        }
    }

    cout << numSeparatedCities << endl;

    return 0;
}
