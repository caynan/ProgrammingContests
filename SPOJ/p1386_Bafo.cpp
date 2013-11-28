# include <iostream>
# include <string>

using namespace std;

int main(){
	int n, c = 1;
	int a, b;

	
	do{
		cin >> n;
		if(n == 0) break;
		int vA = 0, vB = 0;	// victory counter
		for(int i = 0; i < n; i++){
			cin >> a >> b;
			vA+=a;
			vB+=b;
		}
		cout << "Teste " << c++ << '\n';
		string winner = (vA > vB)? "Aldo" : "Beto";
		cout << winner << "\n\n"; 
	}while(true);
}
