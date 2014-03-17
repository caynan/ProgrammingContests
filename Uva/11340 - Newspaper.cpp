/*
user: caynanvls (http://uhunt.felix-halim.net/id/183008)

problem: 11340 - Newspaper 
link: http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=2315
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

	int n, k, m;
	int toPay[256];
	unsigned ll total;

	cin >> n;
	cin.ignore();
	while (n--) {
		total = 0;
		loop (i, 256) {
			toPay[i] = 0;
		}

		sf("%d\n", &k);
		loop (i, k) {
			int p;
			unsigned char c;

			cin >> c >> p;
			cin.ignore();
			toPay[(int) c] = p;
		}

		cin >> m;
		cin.ignore();

		loop (i, m) {
			unsigned char c;
			while ((c = cin.get()) != '\n') {
				total += toPay[(int) c];
			}
		}

		pf("%.2lf$\n", total / 100.0);
	}

}
