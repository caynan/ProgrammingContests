# include <cstdio>

using namespace std;

int main(){
    int count = 1, n, m; 

    while(scanf("%d %d", &n, &m) && (n || m)){
        // declare and populate field
        char field[n][m];
        for(int i = 0; i < n; i++){
            scanf("%s", &field[i]);
            for(int j = 0; j < m; j++){
            }
        }
        if(count > 1) printf("\n");
        printf("Field #%d:\n", count++);
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){  
                if(field[i][j] == '*'){
                    printf("%c", field[i][j]);
                }else{
                // logic
                int result = 0;

                // top-left
                if(i-1 >= 0 && j-1 >= 0){
                    result += (field[i-1][j-1] == '*') ? 1 : 0;
                }
                // top-center
                if(i-1 >= 0){
                    result += (field[i-1][j] == '*') ? 1 : 0;
                }
                // top-right
                if(i-1 >=0 && j+1 < m){
                    result += (field[i-1][j+1] == '*') ? 1 : 0;
                }
                // left
                if(j-1 >= 0){
                    result += (field[i][j-1] == '*') ? 1 : 0;
                }
                // right
                if(j+1 < m){
                    result += (field[i][j+1] == '*') ?  1 : 0;
                }
                // bottom-left
                if(j-1 >= 0 && i+1 < n){
                    result += (field[i+1][j-1] == '*') ? 1 : 0;
                }
                // bottom-center
                if(i+1 < n){
                    result += (field[i+1][j] == '*') ? 1 : 0;
                }
                // bottom-right
                if(j+1 < m && i+1 < n ){
                    result += (field[i+1][j+1] == '*') ? 1 : 0;
                }

                // PRINT
                
                printf("%ld", result);

                }
            }
            printf("\n");
        }   



    }
}