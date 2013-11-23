#include <cstdio>

using namespace std;

int binarySearch(int A[], int min, int max, int key){
    int ret = -1;
    while (max >= min){
        // void use (min + max /2) it can break int size limit
        int mid = (max - min)/2 + min;
        
        // find a match
        if(A[mid] == key) ret = mid;
        // search the upper part
        if(A[mid] < key){
            min = mid + 1;
        }
        // search the bottom part
        else{
            max = mid - 1;
        }
    }
    return ret;
} 

int main(){
    int size, queries, query;
    scanf("%d %d", &size, &queries);
    int arr[size];
    
    // populate arr
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
    
    // search
    for(int i = 0; i < queries; i++){
        scanf("%d", &query);
        printf("%d\n", binarySearch(arr, 0, size-1, query));
    }
}
