#include <iostream>
#include <vector>
#include <iterator>
#include <string>

using namespace std;

int main() {
    // freopen("in.txt", "r", stdin);

    int n, d;
    vector<char> mStack;

    string number;
	while (cin >> n >> d && (n || d)) {
        cin >> number;
        for(const char& currentDigit : number) {
            while ( d > 0 && !mStack.empty() && mStack.back() < currentDigit) {
                // remove element at the top
                mStack.pop_back();
                --d;
            }
            mStack.push_back(currentDigit);
        }
        // how many elements from our queue to consider for our answer
        auto shift = mStack.size() - d;

        // we can't use cout to print a vector, so we use the ostream_iterator.
        ostream_iterator<char> out_it (cout, ""); // iterator for cout
        copy(mStack.begin(), mStack.begin() + shift, out_it); // copy list to out_it
        cout << "\n"; // Add newline after text.

        // clear stack
        mStack.clear();
    }

    return 0;
}
