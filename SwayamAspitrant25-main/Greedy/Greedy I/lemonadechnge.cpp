#include <iostream>
#include <vector>
using namespace std;

bool lemonadeChange(vector<int>& bills) {
    int five = 0, ten = 0;
    for (int b : bills) {
        if (b == 5) five++;
        else if (b == 10) {
            if (five == 0) return false;
            five--; ten++;
        } else { // bill = 20
            if (ten > 0 && five > 0) { ten--; five--; }
            else if (five >= 3) five -= 3;
            else return false;
        }
    }
    return true;
}
int main() {
    int n;
    cout << "Enter number of customers: ";
    if (!(cin >> n) || n < 0) {
        cerr << "Invalid number of customers.\n";
        return 1;
    }
    vector<int> bills(static_cast<size_t>(n));
    if (n > 0) {
        cout << "Enter bills (5, 10, or 20): ";
        for (int i = 0; i < n; i++) {
            if (!(cin >> bills[static_cast<size_t>(i)]) ||
                (bills[static_cast<size_t>(i)] != 5 &&
                 bills[static_cast<size_t>(i)] != 10 &&
                 bills[static_cast<size_t>(i)] != 20)) {
                cerr << "Invalid bill amount.\n";
                return 1;
            }
        }
    }
    bool result = lemonadeChange(bills);
    cout << (result ? "Can provide change to all customers." : "Cannot provide change to all customers.") << endl;
    return 0;
}

/*
Logic: Always give change using higher denominations first to preserve smaller ones.  
Greedy ensures proper handling of 5, 10, 20 bills.  
Time: O(n)
*/