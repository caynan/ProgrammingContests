#include <iostream>

using namespace std;

int main(){
	string s;
	int n, blockSize, i, j, lastJ;

	while(cin >> n && n){
		cin >> s;
		blockSize = s.length()/n;

		lastJ = 0;
		for(i = blockSize - 1; i < s.length(); i+= blockSize){ // end of the block
			for(j = i; j >= lastJ; j--){ // begin of the block
				cout << s[j];
			}
			lastJ += blockSize;
		}
		cout << "\n";
	}

}