# include <cstdio>

using namespace std;

int main(){
    int s, d, a, b, count;
    scanf("%d", &count);
    while(count--){
        scanf("%d %d", &s, &d);
        // s = a + b
        // d = |a - b|
        a = (s - d)/2;
        b = a + d;
        ((a + b) != s || s < d) ?  printf("impossible\n") :
           printf("%d %d\n", b, a);
    }
}
