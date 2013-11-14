# include <cstdio>

int main(){
    int init, c1, c2, c3, ans;
    // 0 = false. stop when all values equal 0.
    while (scanf ("%d %d %d %d", &init, &c1, &c2, &c3),  (init || c1 || c2 || c3)){
        // the 3 full turns.
        ans = 1080;
        // clockwise
        ans += (init < c1) ? (40 - c1 + init)*9 : (init - c1)*9;
        // counter-clockwise
        ans += (c1 < c2) ? (c2 - c1)*9 : (40 - c1 + c2)*9;
        // clockwise
        ans += (c2 < c3) ? (40 - c3 + c2)*9 : (c2 - c3)*9;
    
        // return total degrees
        printf("%d\n", ans);
    }
}
