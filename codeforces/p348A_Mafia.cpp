# include <iostream>
# include <cmath>
# include <algorithm>

using namespace std;

int main(){
	std::ios_base::sync_with_stdio(false); //increase iostream speed

	long double players = 0.0, rounds = 0.0;
	unsigned long temp , biggest = 0;

	cin >> players;
	for(int i = 0; i < players; i++){
		cin >> temp;
		rounds += temp;
		biggest = (temp > biggest) ? temp : biggest;
	} 

	temp = ceil(rounds / (players - 1));
	cout << max(biggest, temp) << '\n';


}