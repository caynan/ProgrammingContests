/* 
 author: Caynan Landim
 problem: 10530 - Guessing Game
 url: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1471
 status: AC (#13229084)
 */

# include <iostream>
# include <cstdio>

using namespace std;

void stanIs();

int main() {
//   freopen("in.txt", "r", stdin);
//   freopen("out.txt", "w", stdout);
//   ios_base::sync_with_stdio(false); // speed up cin/cout (DONT USE with cstdio)

    stanIs();
}

void stanIs(){
    string high = "too high";
    string low = "too low";

    string answer;
    int guess, numPossibilities = 10 + 5;

    bool possibilities[numPossibilities];
    for(int i = 0; i < numPossibilities; i++) possibilities[i] = 1;

    while(cin >> guess && guess != 0){
        getchar(); // to avoid reading \n
        getline(cin, answer);

        if (answer == high) {
            for(int i = guess; i < numPossibilities; i++) possibilities[i] = 0;
        } 
        else if (answer == low) {
            for(int i = 0; i <= guess; i++) possibilities[i] = 0;
        }
        else {  // right on
            if (possibilities[guess]) {
                cout << "Stan may be honest\n";
            } else {
                cout << "Stan is dishonest\n";
            }
            
            // reset possibilities
            for(int i = 0; i < numPossibilities; i++) possibilities[i] = 1;
        }
    }
}
