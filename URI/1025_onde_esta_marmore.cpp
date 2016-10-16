#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int binSearch(vector<int> &mVector, int elem){
    int begin, mid, end;
    begin = 0;
    end = mVector.size() - 1;

    while(begin <= end){
        mid  = (begin + end) / 2;

        // We found it
        if(mVector[mid] == elem) break;

        else if (mVector[mid] > elem) {
            end = mid - 1;
        }
        else {
            begin = mid + 1;
        }
    }

    if(mVector[mid]  == elem){
        int p = mid;
        while(p - 1 >= 0 and mVector[p - 1] == elem)
            p--;
        return p;
    }
    return -1;
}

int main() {
    // freopen("in.txt", "r", stdin);

    int num, query, x, testNum = 1;

    while( (cin >> num >> query) && num && query){
        vector<int> marbles(num);
        for (auto& marble : marbles) {
            cin >> marble;
        }

        sort(marbles.begin(), marbles.end());

        for (auto q = 0; q < query; ++q){
            cin >> x;
            int pos = binSearch(marbles, x);

            cout << "CASE# " << testNum++ << ":" << endl;
            if(pos >= 0)
                cout << x << " found at " << pos +1 << endl;
            else
                cout << x << " not found" << endl;
        }
    }

    return 0;
}
