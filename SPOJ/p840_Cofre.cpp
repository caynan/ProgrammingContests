# include <iostream>

using namespace std;

int main(){
	int n, joao , ze, res = 0, counter = 1;
	cin >> n;
	while(n) { // stops when n == 0
		cout << "Teste " << counter++ << '\n';
		for(int i = 0; i < n; i++){
			cin >> joao >> ze;
			res += joao - ze;
			cout << res << '\n';
		}
		cout << '\n'; // third line must be blank
		res = 0;
		cin >> n;
	}
}
