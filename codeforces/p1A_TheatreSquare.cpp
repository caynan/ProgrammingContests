# include <iostream>
# include <cmath>

using namespace std;

int main(){
	long double n, m, a;
	cin >> n >> m >> a;
	unsigned long long ret = ceil(n/a) * ceil(m/a);
	cout << ret << '\n';
}