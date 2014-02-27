/* 
 author: Caynan Landim
 problem: 514 - Rails
 url: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=455
 status: AC
 */

# include <iostream>
# include <cstdio>
# include <stack>

using namespace std;

void marshalCoaches(int N);

int main() {
//    freopen("in.txt", "r", stdin);
//    freopen("out.txt", "w", stdout);

    int N;
    while (scanf("%d", &N), N) {
        marshalCoaches(N);
        printf("\n");  //empty line between blocks
    }
}

void marshalCoaches(int N) {
    int coach;

    while (true) {
        stack<int> station;
        int lastIn = 0;

        // logic for each case
        for (int numReads = 0; numReads < N; numReads++) {
            scanf("%d", &coach);
            if (coach == 0) return;  // end of current block

            while (lastIn < N && coach != lastIn) {
                if (!station.empty() && station.top() == coach) {
                    break;
                }
                station.push(++lastIn);
            }

            if (station.top() == coach) {
                station.pop();
            }
        }
        
        // print logic
        if (station.empty()) {
            printf("Yes\n");
        } else {
            printf("No\n");
        }
    }
}
