/*
user: caynanvls (http://uhunt.felix-halim.net/id/183008)

problem: 
link: 
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
	read;
	write;

	int n;

	while(gi(n), n){
		priority_queue<int, vector<int>, greater<int>()> numbers;

		while(n--){
			int temp;
			gi(temp);
			numbers.push(temp);
		}
		int sum = 0, cost = 0;
		while(SZ(numbers) > 1){
			sum = numbers.top();
			numbers.pop();
			sum += numbers.top();
			numbers.pop();
			cost += sum;
			numbers.push(sum);
		}

		pf("%d\n", cost);
	}


}