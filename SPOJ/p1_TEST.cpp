// 10552111	 2013-11-28 13:31:44     Caynan	   Life, the Universe, and Everything   accepted  0.00	2.6M  C++ 
# include <iostream>

using namespace std;

int main(){
	int in;
	do{
		cin >> in;
		if (in != 42) cout << in << '\n';
		else break;
	}while(true);
}
