/*
	Use stable_sort, I don't know why yet, but just changing this I got AC.
*/

# include <iostream>
# include <algorithm>

using namespace std;

bool wayToSort(string i, string j);
int unsortednessCalc(string s);

int main(){
	ios_base::sync_with_stdio(false); // speed up 0.1s :)

	int dataSets, lenString, numString, i;
	cin >> dataSets;
	while(dataSets--){
		cin >> lenString >> numString;
		int SIZE = numString;
		string a[SIZE];
		for(i = 0; i < numString; i++){
			cin >> a[i]; 
		}
		
		stable_sort(a, a + SIZE, wayToSort);

		for(i = 0; i < SIZE; i++){
		//	if(i) cout << "\n";
			cout << a[i] << "\n";
		}

		// print newLine between cases
		if(dataSets) cout << "\n";
	}
}

bool wayToSort(string i, string j){
	return unsortednessCalc(i) < unsortednessCalc(j);
}

int unsortednessCalc(string s){
	int ans = 0, len = s.length();
	for (int i = 0; i < len - 1; i++){
		for(int j = i+1; j < len; j++){
			if(s[i] > s[j]) ans++;
		}
	}
	return ans;
}