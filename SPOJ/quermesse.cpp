#include <iostream>

using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int num_participants, test_num = 1;
    while(cin >> num_participants && num_participants != 0) {
        cout << "Teste " << test_num++ << "\n";
        int temp;
        for (auto i = 1; i <= num_participants; ++i) {
            cin >> temp;
            if (temp == i) {
                cout << i << "\n\n";
            }
        }
    }

    return 0;
}
