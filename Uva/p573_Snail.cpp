# include <cstdio>

using namespace std;

int main(){
    double  h, u, d, f;
    // stops when h == 0 (false)
    while(scanf("%lf %lf %lf %lf", &h, &u, &d, &f),  h){
        int day = 0;
        double ht = 0.0;
        // calculate fatigue factor
        f *= u/100;
        
        while(true){
            day++;
            // climbed
            if(u > 0) ht += u;
            u -= f; // new climb distance, after fatigue factor
            
            // out of the well
            if (ht > h) break;
            
            // slided
            ht -= d;

            // back to the bottom
            if (ht < 0) break;
        }
        (ht >= 0) ?  printf("success on day %d\n", day) : printf("failure on day %d\n", day);
    }
}
