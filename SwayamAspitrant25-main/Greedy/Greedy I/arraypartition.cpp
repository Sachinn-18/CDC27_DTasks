#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int arrayPairSum(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int sum = 0;
    for (size_t i = 0; i < nums.size(); i += 2)
        sum += nums[i];
    return sum;
}
int main() {
    int n;
    cout << "Enter number of elements (even): ";
    if (!(cin >> n) || n < 0) {
        cerr << "Invalid number of elements.\n";
        return 1;
    }
    if (n % 2 != 0) {
        cerr << "Number of elements must be even.\n";
        return 1;
    }
    vector<int> nums(static_cast<size_t>(n));
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        if (!(cin >> nums[i])) {
            cerr << "Invalid input.\n";
            return 1;
        }
    }
    int result = arrayPairSum(nums);
    cout << "Maximum sum of min pairs: " << result << endl;
    return 0;
}

/*
Logic: Sorting ensures pairing smallest two together gives max sum of mins.  
Greedy takes every alternate element after sort.  
Time: O(n log n)
*/
