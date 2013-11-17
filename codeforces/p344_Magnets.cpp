# include <cstdio>

using namespace std;

int main(){
	unsigned n = 0, ans = 0, actual = 0, last = 0;
	scanf("%d", &n);
	while (n--){
		scanf("%d", &actual);
		ans += (actual == last) ? 0 : 1;
		last = actual;	
	}
	printf("%d\n", ans);
}