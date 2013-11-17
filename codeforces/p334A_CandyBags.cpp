# include <cmath>
# include <iostream>

using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false); // speedup iostream
	int n = 0, nSquared, i = 0, j = 0;

	// number of brothers
	cin >> n;
	nSquared = pow(n,2);

	// division for each brother (remember AP)
	for(i = 1; i <= nSquared/2; i++){
		// insert space between combinations
		if (j > 0) cout << " ";
		
		// tuple combination: i (2^n - i) + 1
		cout << i << " " << (nSquared - i + 1);
		j++; 

		// new line
		if(i % (n/2) == 0){
			cout << "\n";
			// reset j	
			j = 0;	
		} 		
	} 
}