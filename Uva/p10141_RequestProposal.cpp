# include <cstdio>
# include <iostream>

using namespace std;

unsigned n, p, r, count=1, bestCompliance;
double  d, bestPrice;
string line, name, bestProposal;

int main(){
    // stops when n==0 and p==0
    while(scanf("%d %d", &n, &p), n||p){
        bestPrice = 1E35;
        bestCompliance = 0;

        //read and ignore requirement names
        for(int j = 0; j < n; j++){
            cin.ignore();
            getline(cin, line);
        }
        
        // analyze each proposal    
        for (int i = 0; i < p; i++){
            getline(cin, name); // get proposal name
            scanf("%lf %d", &d, &r); // get price and req. met

            // read and ignore met requirement names
            for (int j = 0; j < r; j++){
                cin.ignore();
                getline(cin, line);
            }

            // logic to find best proposal
            if(r > bestCompliance ||
                    (r == bestCompliance && d < bestPrice )){
                bestCompliance = r;
                bestProposal = name;
                bestPrice = d;
            }
        }
        if (count > 1) cout << '\n';
        cout << "RFP #" << count++ << '\n';
        cout << bestProposal << '\n';
    }
}
