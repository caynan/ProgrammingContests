#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int qtyBlocks(vector<int>& blockSizes, int desiredLength) {
    // sort block sizes
    sort(blockSizes.begin(), blockSizes.end());

    // case desiredLength is a multiple of the biggest blockSize.
    if (desiredLength % blockSizes.back() == 0) {
        return desiredLength / blockSizes.back();
    }

    // create list to memoize sub-results, set value to "infinity"
    vector<int> memoize(1000010, 999999);
    memoize[0] = 0;

    for (auto const& blockSize : blockSizes) {
        for (auto i = blockSize; i <= desiredLength; ++i) {
            memoize[i] = min(memoize[i], memoize[i - blockSize] + 1);
        }
    }

    return memoize[desiredLength];
}

int main() {
    int numCases, numBlockTypes, desiredLength;
    vector<int> blockSizes;

    cin >> numCases;

    while (numCases--) {
        cin >> numBlockTypes >> desiredLength;

        int temp;
        for (auto i = 0; i < numBlockTypes; ++i) {
            cin >> temp;
            blockSizes.push_back(temp);
        }

        auto ans = qtyBlocks(blockSizes, desiredLength);
        cout << ans << endl;

        // empty block size
        blockSizes.clear();
    }

    return 0;
}
