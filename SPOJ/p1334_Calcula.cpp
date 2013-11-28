# include <iostream>

using namespace std;

int main(){
	int res = 0,  n = 1, in, r;
	
	cin >> r;
	while(r){
		// calculate sum
		for(int i = 0; i < r; i++){
			cin >> in;
			res += in;
		}
		// output
		cout << "Teste " << n++ << '\n';		
		cout << res << "\n\n";
		
		// receive new number and reset res
		cin >> r;
		res = 0;
	}
}
