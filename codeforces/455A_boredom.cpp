#include <iostream>

using namespace std;

const int MAX_NUM =  100010;

int main(){
    long long dp[MAX_NUM] = {0};
    long long countPoints[MAX_NUM] = {0};

	int n,x;
	cin >> n;
	for (auto i = 0; i < n; ++i) {
		cin >> x;
		countPoints[x]++;
	}

    dp[0] = 0;
	dp[1] = countPoints[1];
	for(auto i = 2; i < MAX_NUM; i++){
		dp[i] = max(dp[i - 1], dp[i - 2] + i * countPoints[i]);
	}
	cout << dp[MAX_NUM - 1] << endl;
}
