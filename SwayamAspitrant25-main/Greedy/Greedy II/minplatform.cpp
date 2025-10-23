#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int findMinPlatform(vector<int>& arrival, vector<int>& departure) {
    if (arrival.empty()) return 0;
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int plat_needed = 1, res = 1;
    int i = 1, j = 0;

    while (i < arrival.size() && j < departure.size()) {
        if (arrival[i] <= departure[j]) {
            plat_needed++;
            i++;
        } else {
            plat_needed--;
            j++;
        }
        res = max(res, plat_needed);
    }
    return res;
}
int main() {
    int n;
    cout << "Enter number of trains: ";
    if (!(cin >> n) || n < 0) {
        cerr << "Invalid number of trains.\n";
        return 1;
    }
    vector<int> arrival(static_cast<size_t>(n));
    vector<int> departure(static_cast<size_t>(n));
    if (n > 0) {
        cout << "Enter arrival times of trains:\n";
        for (int i = 0; i < n; i++) {
            if (!(cin >> arrival[static_cast<size_t>(i)] ) || arrival[static_cast<size_t>(i)] < 0) {
                cerr << "Invalid arrival time.\n";
                return 1;
            }
        }
        cout << "Enter departure times of trains:\n";
        for (int i = 0; i < n; i++) {
            if (!(cin >> departure[static_cast<size_t>(i)] ) || departure[static_cast<size_t>(i)] < 0 ||
                arrival[static_cast<size_t>(i)] > departure[static_cast<size_t>(i)]) {
                cerr << "Invalid departure time or arrival time greater than departure time.\n";
                return 1;
            }
        }
    }
    int result = findMinPlatform(arrival, departure);
    cout << "Minimum number of platforms required: " << result << endl;
    return 0;
}
/*
Logic: Sort arrivals and departures.  
Increment platforms if next train arrives before one departs; otherwise, free one.  
Time: O(n log n)
*/
