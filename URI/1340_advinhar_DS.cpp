#include <iostream>
#include <stack>
#include <queue>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int num_tests;
    while(cin >> num_tests) {
        int command, num;

        bool isStack = true,
             isQueue = true,
             isPriorityQueue = true;

        stack<int> mStack;
        queue<int> mQueue;
        priority_queue<int> mPQueue;

        for(auto i = 0; i < num_tests; i++) {
            cin >> command >> num;
            if (command == 1) {
                if(isStack) mStack.emplace(num);
                if(isQueue) mQueue.emplace(num);
                if(isPriorityQueue) mPQueue.emplace(num);
            }
            else {
                // check if is Stack
                if (isStack && !mStack.empty() && mStack.top() == num) {
                    mStack.pop();
                } else {
                    isStack = false;
                }

                // Check if is Queue
                if (isQueue && !mQueue.empty() && mQueue.front() == num) {
                    mQueue.pop();
                } else {
                    isQueue = false;
                }

                // Check if is Priority Queue
                if (isPriorityQueue && !mPQueue.empty() && mPQueue.top() == num) {
                    mPQueue.pop();
                } else {
                    isPriorityQueue = false;
                }
            }
        }

        string ans;
        // check if is Stack OR queue OR priority queue
        if (isStack && !isQueue && !isPriorityQueue) ans = "stack";
        else if (isQueue && !isStack && !isPriorityQueue) ans = "queue";
        else if (isPriorityQueue && !isQueue && !isStack) ans = "priority queue";

        // check if  is impossible
        else if (!isStack && !isQueue && !isPriorityQueue) ans = "impossible";

        // if none of the above it means that we have more than two possible
        else ans = "not sure";

        cout << ans << "\n";
    }

    return 0;
}
