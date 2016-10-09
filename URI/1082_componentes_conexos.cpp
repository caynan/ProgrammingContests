#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // Apparently memset needs this on some versions of g++, funny :)

using namespace std;

bool adjMatrix[27][27];
bool visited[27];
vector<int> neighbors;
int numVertices, numEdges;


void dfs(int vertex) {
    visited[vertex] = true;
    neighbors.push_back(vertex);

    for (auto next = 0; next < numVertices; ++next) {
        if (adjMatrix[vertex][next]) {
            // check if we already visited the vertex `next`
            if (!visited[next]) {
                dfs(next);
            }
        }
    }
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int N;
    cin >> N;

    for(auto caseNum = 1; caseNum <= N; ++caseNum) {
        // reset global variables adjMatrix, visited, neighbors
        memset(adjMatrix, false, sizeof(adjMatrix));
        memset(visited, false, sizeof(visited));
        neighbors.clear();

        // counter of the number of connected components in our graph
        int numConnectedComponents = 0;

        cin >> numVertices >> numEdges;

        // get all the edges
        char vertex1, vertex2;
        for (auto i = 0; i < numEdges; ++i) {
            cin >> vertex1 >> vertex2;
            // we subtract 97 (code for `a`) to get the int representation of the char.
            adjMatrix[(int) vertex1 - 97][(int) vertex2 - 97] = true;
            adjMatrix[(int) vertex2 - 97][(int) vertex1 - 97] = true;
        }

        // print case number
        cout << "Case #" << caseNum << ":\n";

        // for all the Vertices, we get the connected components and print them
        for (auto vertex = 0; vertex < numVertices; ++vertex) {
            if (!visited[vertex]) {
                numConnectedComponents++;
                //call dfs on the given unvisited vertex
                dfs(vertex);
                // Sort neighbors of vertex
                sort(neighbors.begin(), neighbors.end());
                for (auto const& v : neighbors) {
                    // convert back from int to char
                    char v_char = v + 97;
                    cout << v_char << ",";
                }
                cout << "\n";
            }
            // clear neighbors, to use on next vertex
            neighbors.clear();
        }

        cout << numConnectedComponents << " connected components\n\n";
    }

    return 0;
}
