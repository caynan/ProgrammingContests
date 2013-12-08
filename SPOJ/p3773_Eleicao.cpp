# include <iostream>
# include <map>

using namespace std;

int main(){
	typedef map<int, int> ii;
	ii votes;
	int numberOfVotes = 0, temp = 0, winner, winnerVotes = 0;

	cin >> numberOfVotes;
	// receive votes
	for(int i = 0; i < numberOfVotes; i++){
		cin >> temp;
		++votes[temp];		
	}

	// iterate over elements on map, and find the one with
	// bigger value.
	ii::const_iterator end = votes.end();
	for(ii::const_iterator it = votes.begin(); it != end; it++){
		if(it->second > winnerVotes){
			winner = it->first;
			winnerVotes = it->second;
		}
	}
	// print winner
	cout << winner << '\n';
}