#include <iostream>
#include <string>

using namespace std;

const int SUM = 285;

bool isBoardValid(int matrix[9][9]) {
    int entry,
        rowSum[9] = {0},
        colSum[9] = {0},
        sumSubMatrix[3][3] = {0};

    bool ans = true;

    // Check if sudoku board is valid (rows and columns)
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            entry = matrix[i][j];
            entry *= entry;

            // Add entry value to rowSum, colSum and sumSubMatrix[i/3][j/3]
            rowSum[i] += entry;
            colSum[j] += entry;
            sumSubMatrix[i/3][j/3] += entry;

            // Stop checking case we reached last row, and the column sum != SUM
            if (i == 8 && colSum[j] != SUM){
                ans = false;
                break;
            }
        }

        // Stop checking if our ans is already false OR row has a SUM != 285
        if (!ans || rowSum[i] != SUM){
            ans =  false;
            break;
        }
    }

    // check if sub matrices are valid, only if rows and cols are valid
    if (ans) {
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (sumSubMatrix[i][j] != SUM) {
                    ans = false;
                    break;
                }
            }

            // case one of our sub matrix is invalid we don't need to keep checking.
            if (!ans) break;
        }
    }

    // we return true case our sumRow and sumCol and sumSubMatrix are valid.
    return ans;
}

int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int numTests;
    int matrix[9][9];
    string ans = "";
    cin >> numTests;

    // Check if board is valid for each test case
    for(int testNum = 1; testNum <= numTests; ++testNum) {
        // Populate matrix
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                cin >> matrix[i][j];
            }
        }

        // check if board is valid
        ans = (isBoardValid(matrix)) ? "SIM" : "NAO";

        // Print result
        cout << "Instancia " << testNum << "\n";
        cout << ans << "\n\n";
    }

    return 0;
}
