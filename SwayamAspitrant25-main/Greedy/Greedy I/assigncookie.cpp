#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

int findContentChildren(vector<int>& greed, vector<int>& cookies) {
    sort(greed.begin(), greed.end());
    sort(cookies.begin(), cookies.end());
    size_t i = 0, j = 0;
    while (i < greed.size() && j < cookies.size()) {
        if (cookies[j] >= greed[i]) ++i; // child satisfied
        ++j;
    }
    return static_cast<int>(i);
}

int main() {
    int n, m;
    cout << "Enter number of children and cookies: ";
    cin >> n >> m;
    vector<int> greed(n), cookies(m);
    cout << "Enter greed factors of children: ";
    for (int i = 0; i < n; i++) cin >> greed[i];
    cout << "Enter sizes of cookies: ";
    for (int j = 0; j < m; j++) cin >> cookies[j];

    int satisfiedChildren = findContentChildren(greed, cookies);
    cout << "Maximum number of satisfied children: " << satisfiedChildren << endl;
    return 0;
}

/*
Logic: Sort both lists. Assign smallest available cookie to smallest greedy child.  
Greedy choice ensures maximum satisfied children.  
Time: O(n log n)
*/
