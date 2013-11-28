# include <iostream>
# include <string>

using namespace std;

int main(){
	int n,k;
	string in;
	cin >> n >> k;
	int ret = n, counter;


	while (n){
		counter = 0;
		cin >> in;
		// count 4s and 7s
		for(string::iterator it=in.begin(); it != in.end(); ++it){
			if(*it == '4') counter++;
			if(*it == '7') counter++;
		}
		if(counter >= k) ret--;
		n--;
	}
	cout << ret << '\n';
}