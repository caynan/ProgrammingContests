#include <iostream>
using namespace std;

int main() {
    int n, t[10][10];

    cin >> n;
    while( n-- ) {
        for( int i=1; i<=9; i+=2 )
            for( int j=1; j<=i; j+=2 )
                cin >> t[i][j];

        for( int j=2, k=1; j<=8; j+=2, k+=2 )
            t[9][j] = ( t[7][k] - t[9][j-1] - t[9][j+1] )/2;

        for( int i=8; i>=2; i-- )
            for( int j=1; j<=i; j++ )
                t[i][j] = t[i+1][j] + t[i+1][j+1];

        for( int i=1; i<=9; i++ ) {
            for( int j=1; j<=i; j++ )
                cout << t[i][j] << ( j == i ? "" : " " );
            cout << endl;
        }
    }
}
