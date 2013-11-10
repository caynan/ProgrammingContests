# include <stdio.h>

int cycle(int num){
    // return the number of cycles
    int cycles = 1;
    while(num != 1){
        if(num % 2 != 0){
            num = 3*num + 1;
        }
        else{
            num = num/2;
        }
        cycles++;
    }
    return cycles;
}

int main(){
    int m,originalM, n, originalN, max;
    int i;
    int temp;
    
    while((scanf("%d %d", &m,&n)) == 2){
        originalM = m;
        originalN = n;

        // swap if inverted
        if(m > n){
            temp = m;
            m = n;
            n = temp;
        }

        max = cycle(m);
        for(i = m+1; i <= n; i++){
            temp = cycle(i);
            if(max < temp){
                max = temp;
            }
        }
        printf("%d %d %d\n", originalM, originalN, max);
    }
}
