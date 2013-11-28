// 5286305	 Nov 28, 2013 4:21:28 PM	caynan	 275A - Lights Out	 GNU C++	Accepted	 30 ms	 0 KB

# include <iostream>
using namespace std;

bool isOn(int m[3][3], int i, int j){
	// 1 is the neutral element of the sum
	int ret = m[i][j];
	
	// hasLeft
	ret += (j > 0)? m[i][j-1] : 0;
	// hasRight
	ret += (j < 2)? m[i][j+1] : 0;
	// hasUp
	ret += (i > 0)? m[i -1][j] : 0;
	// hasDown
	ret += (i < 2)? m[i + 1][j] : 0;
	
	// if the sum of all adjacent elements is even, than it is turned on. 
	return (ret % 2 == 0);
}

int main(){
	// create and populate matrix
	int m[3][3];
	for (int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cin >> m[i][j];
		}
	}
	
	// create matrix to return
	int ret[3][3];
	for (int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			ret[i][j] = (isOn(m, i, j)) ? 1 : 0;
		}
	}
	
	// print the result
	for (int i = 0; i < 3; i++){
		for(int j = 0; j < 3; j++){
			cout << ret[i][j];
		}
		if (i < 2) cout << '\n';
	}
}



