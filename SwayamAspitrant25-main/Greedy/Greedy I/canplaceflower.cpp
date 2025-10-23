#include <iostream>
#include <vector>
using namespace std;

bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n <= 0) return true;
    size_t count = 0;
    for (size_t i = 0; i < flowerbed.size(); ++i) {
        if (flowerbed[i] == 0 &&
            (i == 0 || flowerbed[i - 1] == 0) &&
            (i + 1 == flowerbed.size() || flowerbed[i + 1] == 0)) {
            flowerbed[i] = 1;
            ++count;
            if (static_cast<int>(count) >= n) return true;
        }
    }
    return static_cast<int>(count) >= n;
}

int main() {
    int m, n;
    cout << "Enter size of flowerbed and number of flowers to plant: ";
    if (!(cin >> m >> n) || m < 0 || n < 0) {
        cerr << "Invalid input.\n";
        return 1;
    }
    vector<int> flowerbed(static_cast<size_t>(m));
    if (m > 0) {
        cout << "Enter flowerbed (0 for empty, 1 for planted): ";
        for (int i = 0; i < m; ++i) {
            if (!(cin >> flowerbed[static_cast<size_t>(i)])) {
                cerr << "Invalid input.\n";
                return 1;
            }
        }
    }
    bool result = canPlaceFlowers(flowerbed, n);
    cout << (result ? "Can plant all flowers." : "Cannot plant all flowers.") << endl;
    return 0;
}

/*
Logic: Check if current position and neighbors are empty.  
Plant greedily to maximize placement count.  
Time: O(n)
*/
