#include <iostream>
#include <iterator>
#include <vector>
#include <queue>

using namespace std;

const int MAX_DISTANCE = 200100;

vector<int> distances, shortcut;
vector<bool> visited;

void calculateShortestPaths(int n) {
    // queue... it's a BFS remmember :p
    queue<int> mQueue;

    // initialize all distances to `MAX_DISTANCE`
    fill(distances.begin(), distances.end(), MAX_DISTANCE);

    // set distances to initial point to zero
    distances[1] = 0;
    // to start the magic, we insert our initial point into the queue.
    mQueue.push(1);
    // we also set it is visited (we set the zero indexed value, just for sanity sake)
    visited[0] = visited[1] = true;

    int current;
    while(!mQueue.empty()) {
        current = mQueue.front(); mQueue.pop();

        // check if next intersection distance is bigger than the distance to
        // current + 1, if it's it means we just found a better way
        if (current < n && distances[current + 1] > distances[current] + 1) {
            // set new distances to next node
            distances[current + 1] = distances[current] + 1;

            // standard procedure to avoid cycles, check if visited, add to
            // queue, mark as visited... you know the drill
            if (!visited[current + 1]) {
                mQueue.push(current + 1);
            }
            visited[current + 1] = true;
        }

        // check if previous intersection distance is bigger than the distance to
        // current + 1, if it's it means we found a better way
        if (current > 1 && distances[current - 1] > distances[current] + 1) {
            // set new distances to previous node
            distances[current - 1] = distances[current] + 1;

            // standard procedure to avoid cycles, check if visited, add to
            // queue, mark as visited... you know the drill
            if (!visited[current - 1]) {
                mQueue.push(current - 1);
            }
            visited[current - 1] = true;
        }

        // check if distance to the intersection we can go using our shortcut is
        // bigger than distance to current + 1, if it's it means we found a better way.
        if (distances[shortcut[current]] > distances[current] + 1) {
            // set new distances to shortcut intersection
            distances[shortcut[current]] = distances[current] + 1;

            // standard procedure to avoid cycles, check if visited, add to
            // queue, mark as visited... you know the drill
            if (!visited[shortcut[current]]) {
                mQueue.push(shortcut[current]);
            }
            visited[current - 1] = true;
        }
    }
    // here all the distancess on our global vector distances is the minimal distance o/
}

int main() {
    // number of intersections
    int n;
    cin >> n;

    // initialize vectors to avoid segfault
    distances.resize(n + 1); shortcut.resize(n + 1); visited.resize(n + 1);

    // get all shortcuts
    for (auto i = 1; i <= n; ++i) {
        cin >> shortcut[i];
    }

    // run bfs to find smallest path for each intersection
    calculateShortestPaths(n);

    // print results separated by space (remember that the first element
    // is the zero indexed value, which doesn't exist, so we jump it)
    ostream_iterator<int> out_it(cout, " ");
    copy(distances.begin()+1, distances.end(), out_it);
    cout << "\n";
}
