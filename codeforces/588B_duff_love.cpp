#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

typedef long long ll;
int seen[1000010];
int prime[80000];
ll prime2[80000];
int nprime;

void getprime() {
    nprime = 0;
    memset(seen, 0, sizeof(seen));
    for(auto i = 2; i <= 1000000; ++i){
        int t = 1000000 / i;
        for(auto j = 2; j <=t; ++j) {
            seen[i * j] = 1;
        }
    }

    for(auto i = 2; i <= 1000000; ++i){
        if(!seen[i]) {
            prime[nprime] = i;
            prime2[nprime++] = (ll) i * i;
        }
    }
}

int main(){
    // Pre-compute all prime nums.
    getprime();

    ll n;
    cin >> n;
    for(auto i = 0; i < nprime; i++){
        if(n % prime2[i] == 0){
            while(n % prime2[i] == 0) {
                n /= prime[i];
            }
        }
    }

    cout << n << endl;

    return 0;
}
