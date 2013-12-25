# include <cstdio>
# define LIMIT 500001

using namespace std;

int main(){
    unsigned n, b, h, w;
    while (scanf("%d %d %d %d", &n, &b, &h, &w)!= EOF){
        unsigned price, beds, bstPrice = LIMIT, temp;
        // repeat for each hotel
        for (int i = 0; i < h; i++){
            scanf("%d", &price);
            // calculate the cost, and if possible (enough beds)
            // change bstPrice to min(bstPrice, price)
            for(int j = 0; j < w; j++){
                scanf("%d", &beds);
                if(beds >= n){
                    temp = n * price;
                    bstPrice = (temp <= b && temp < bstPrice)? temp : bstPrice;
                }
            }
        }
        // bstPrice == LIMIT when no hotel satisfay the conditions
        // return the bstPrice among all hotels.
        (bstPrice==LIMIT) ? printf("stay home\n") : printf("%d\n", bstPrice);
    }

}
