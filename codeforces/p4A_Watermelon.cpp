# include <iostream>

using namespace std;

int main(){
	int w;

	cin >> w;
	// if w % 2 == 0, than is possible, but 0 == false.
	cout << ((w % 2) ? "NO" : (w > 2)?"YES":"NO") << "\n";
}