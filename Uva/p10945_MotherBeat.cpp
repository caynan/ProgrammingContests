#include <iostream>

using namespace std;

bool isPalindrome(string w){
	// polish w
	string wP;
	for(int i = 0; i < w.length(); i++){
		char temp = tolower(w[i]);
		if(!isalpha(w[i])) continue;
		wP += tolower(w[i]);
	}
	// test if Palindrome
	int len = wP.length();
	for(int i = 0; i < len/2; i++){
		if(wP[i] != wP[len-i-1]) return false;
	}
	return true;

}

int main(){
	string testString;
	while(getline(cin, testString, '\n'),testString != "DONE"){	
		bool pali = isPalindrome(testString);
		if(pali){
			cout << "You won't be eaten!\n";
		}else{
			cout << "Uh oh..\n";
		}
	}
}

