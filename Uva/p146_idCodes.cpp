# include <iostream>
# include <algorithm>

using namespace std;

int main(){
	string s;
	while(cin >> s, s != "#"){
		// next_permutation returns false if s is the last 
		// in lexicographic order combination, or modifies s
		// to the next possible permutation
		if(next_permutation(s.begin(), s.end())){
			cout << s << "\n";
		}else{
			cout << "No Successor\n";
		}
	}
}