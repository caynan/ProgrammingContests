# include <stdio.h>

int main(){
    int nextRound = 0; 
    int temp = 0;
    int lastRead = 0;
    int n, k;
    int i = 0;

    // read from stdin n and k (num participants and k-th place
    scanf("%d %d", &n, &k);

    for (i = 0; i < n; i++){
        // receive each grade
        scanf("%d", &temp);
        if(i < k && temp > 0){
            lastRead = temp;
            nextRound++;
        }
        else if(temp == lastRead && temp > 0){
            nextRound++;
        }
    }

    printf("%d\n", nextRound);
}
        
