/*
user: caynanvls (http://uhunt.felix-halim.net/id/183008)

problem: 591 - Box of Bricks
link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=532
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
//	write;
//	read;

	int SIZE = 50 + 5;
	int blocksOnStack[SIZE];
	int numStacks, count = 1;
	while(gi(numStacks) && numStacks != 0){
		int sum = 0, i;
		loop(i, numStacks){
			gi(blocksOnStack[i]);
			sum += blocksOnStack[i];
		}
		
		int average = sum / numStacks;
		
		int sumAbsDiff = 0;
		loop(i, numStacks){
			sumAbsDiff += abs(blocksOnStack[i] - average);
		}

		// divide by two because we're counting the blocks to change twice ;)
		// you could also, only sum the values that are bigger than the average.
		int ans = sumAbsDiff / 2;

		pf("Set #%d\n", count++);
		pf("The minimum number of moves is %d.\n\n", ans);

	}


}