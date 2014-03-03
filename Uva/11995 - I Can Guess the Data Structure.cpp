/*
user: caynanvls (http://uhunt.felix-halim.net/id/183008)

problem: 11995 - I Can Guess the Data Structure!
link: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=3146
*/
 
# include <iostream>
# include <cstdio>
# include <cstring>
# include <cstdlib>
# include <cmath>
 
# include <algorithm>
# include <vector>
# include <queue>
# include <stack>
# include <map>
# include <utility>
# include <functional>
 
 
#define FOR(i, s, e) for(int i=s; i<e; i++)
#define loop(i, n) FOR(i, 0, n)
#define tr(cont, it) for(typeof(cont.begin()) it=cont.begin() ; it != cont.end() ; it++)
#define gi(a) sf("%d", &a)
#define gi2(a, b) sf("%d%d", &a, &b)
#define gi3(a, b, c) sf("%d%d%d", &a, &b, &c)
#define gi4(a, b, c, d) sf("%d%d%d%d", &a, &b, &c, &d)
#define sf scanf
#define pf printf
#define pb push_back
#define MP make_pair
#define fr first
#define sc second
#define ll long long
#define dd double
#define all(v) v.begin(), v.end()
#define PI acos(-1.0)
#define mem(ara, value) memset(ara, value, sizeof(ara))
#define paii pair<int, int>
#define pall pair<ll, ll>
#define SZ(a) int(a.size())
#define read freopen("input.txt", "r", stdin)
#define write freopen("output.txt", "w", stdout)
 
using namespace std;

int main(){
//	read;
//	write;
	
	int n;
	while(cin >> n){
		queue<int> q;
		stack<int> s;
		priority_queue<int> pq;

		bool isQueue = true, isStack = true, isPriorityQueue = true;
		int i, command, value;
		loop(i, n){
			cin >> command >> value;

			// command to insert element on the X data structure
			if (command == 1) {
				if (isPriorityQueue) pq.push(value);
				if (isQueue) 		 q.push(value);
				if (isStack) 		 s.push(value);
			}
			// command to remove element from the X data structure
			else {
				isPriorityQueue &= !pq.empty() && pq.top() == value;
				isQueue 		&= !q.empty() && q.front() == value;
				isStack 		&= !s.empty() && s.top() == value;
				// if is possible, pop element from X data structure
				if (isPriorityQueue) pq.pop();
				if (isQueue)		 q.pop();
				if (isStack)		 s.pop();
			}
		}

		// answer logic
		if(isPriorityQueue + isQueue + isStack > 1){
			pf("not sure\n");
		} else if (isPriorityQueue) {
			pf("priority queue\n");
		} else if (isQueue) {
			pf("queue\n");
		} else if (isStack){
			pf("stack\n");
		} else {
			pf("impossible\n");
		}
	}
}