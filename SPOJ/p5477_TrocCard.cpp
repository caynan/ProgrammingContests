# include <cstdio>
# include <algorithm>
# include <set>

using namespace std;

int main(){
    int A, B, min, temp, result;
       
    while(scanf("%d %d", &A, &B) && A != 0 && B != 0){
        set<int> aCards;
        set<int> bCards;
        set<int> v;
        set<int> aMinusB;
        set<int> bMinusA;

        //Receive A and B cards
        for(int i = 0; i < A; i++){
            scanf("%d", &temp);
            aCards.insert(temp);
        }
        for(int j = 0; j < B; j++){
            scanf("%d", &temp);
            bCards.insert(temp);
        }
        
        // v = (A - B) U (B - A) 
        set_difference(aCards.begin(), aCards.end(),
                       bCards.begin(), bCards.end(),
                       inserter(aMinusB, aMinusB.begin()));
        set_difference(bCards.begin(), bCards.end(),
                       aCards.begin(), aCards.end(),
                       inserter(bMinusA, bMinusA.begin()));
        set_union(aMinusB.begin(), aMinusB.end(),
                  bMinusA.begin(), bMinusA.end(),
                  inserter(v, v.begin()));

        //result and print it
        min = (aMinusB.size() > bMinusA.size())? bMinusA.size() : aMinusB.size();
        // divide by 2, as we want the number of exchanges (2 cards per exchange)
        result = (v.size()/2 > min)? min : v.size()/2;
        printf("%d\n", result);
    }
}
