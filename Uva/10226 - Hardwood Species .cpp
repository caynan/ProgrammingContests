/*
user: caynanvls (http://uhunt.felix-halim.net/id/183008)

problem: 10226 - Hardwood Species 
link: http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1167
*/
 
// TODO REMEMBER TO TRY THIS PROBLEM WITH TRIE LATER

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
	string treeName;
	map<string, double> log;

    sf("%d\n", &n);
	while (n--) {
		int count = 0;

		while (true) {
			getline(cin, treeName);
			if (treeName == "") break;

			count++;
			log[treeName]++;
		}
		tr(log, it){
			pf("%s %.4lf\n", it->first.c_str(), it->second*100 / (double) count);
		}

		//prepare for next test case
		if(n > 0){
			log.clear();
			pf("\n");
		}

	}

}