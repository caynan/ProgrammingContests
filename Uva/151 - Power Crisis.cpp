/*
user: caynanvls (http://uhunt.felix-halim.net/id/183008)

problem: 151 - Power Crisis
link: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=87
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
	while(gi(n), n){
		int i;

		int m = 1;
		while (true) {
			vector<int> cities;
			for(int i = 1; i <= n; i++) cities.pb(i);

			int index = 0;
			while (cities[index] != 13) {
				cities.erase(cities.begin() + index);
				index += m - 1;
				if (index >= SZ(cities)) index = (index % SZ(cities));
			}

			if (SZ(cities) == 1) {
				pf("%d\n", m);
				break;
			} else {
				m++;
			}
		}
	}
}

