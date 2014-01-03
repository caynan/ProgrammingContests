# include <iostream>
# include <cstdio>
# include <map>
// # include <string>

using namespace std;

bool isMirrored (string s);
bool isPalindrome (string s);

map <char, char> mapRev;

int main(){
    string in;
    string character = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
    string reverse   = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";
    
    // populate mapRev
    for(int i = 0; i < character.length(); i++){
        mapRev[character[i]] = reverse[i];
    }

    while(cin >> in){
        string out;
        bool isP = isPalindrome(in);
        bool isM = isMirrored(in);
       
        // test for each case
        if (!isP && !isM)     out = " -- is not a palindrome.";
        else if (isP && !isM) out = " -- is a regular palindrome.";
        else if (!isP && isM) out = " -- is a mirrored string.";
        else if (isP && isM)  out = " -- is a mirrored palindrome.";

        // print the output
        cout << in << out << "\n\n"; 
    }
}

bool isMirrored (string s){
    int length = s.length();
    // should test the middle char when s is odd
    int limitInter = length / 2 + length % 2;
    
    for (int i = 0; i < limitInter; i++){
        if (mapRev[s[i]] != s[length - i - 1])
            return false;
    }
    return true;
}

bool isPalindrome (string s){
    int length = s.length();
    int limitInter = length / 2;
    
    for (int i = 0; i < limitInter; i++){
        if (s[i] != s[length - i -1])
            return false;
    }
    return true;
}


