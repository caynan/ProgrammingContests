#include <iostream>
#include <vector>

using namespace std;

int main(){
    int value, temp;
    vector<int> notes = {100, 50, 20, 10, 5, 2, 1};

    cin >> value;
    cout << value << "\n";

    for (int note : notes) {
        cout << value / note <<  " nota(s) de R$ " << note << ",00" << "\n";
        value %= note;
    }

    return 0;
}
