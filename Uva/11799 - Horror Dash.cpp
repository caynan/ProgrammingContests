# include <cstdio> // std::scanf, std::printf
# include <algorithm> // std::sort
# include <functional> // std::greater

using namespace std;

const int SIZE = 105;

int main(){
    int T, cases = 1;
    scanf("%d", &T);
    while(T--){
        int arr[SIZE] = {0} ;
        int n, temp;
        scanf("%d", &n);
        for (int i = 0; i < n;i++){
            scanf("%d", &arr[i]);
        }
        
        sort(arr, arr + SIZE, greater<int>());

        printf("Case %d: %d\n", cases++, arr[0]);
    }
}
