#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int start, end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}

int activitySelection(vector<Activity>& activities) {
    if (activities.empty()) return 0;
    sort(activities.begin(), activities.end(), compare);
    int count = 1;
    int lastFinish = activities[0].end;

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= lastFinish) {
            count++;
            lastFinish = activities[i].end;
        }
    }
    return count;
}

/*
Logic: Sort activities by end time; pick next that starts after previous ends.  
Greedy ensures max non-overlapping activities.  
Time: O(n log n)
*/
int main() {
    int n;
    cout << "Enter number of activities: ";
    if (!(cin >> n) || n < 0) {
        cerr << "Invalid number of activities.\n";
        return 1;
    }
    vector<Activity> activities(static_cast<size_t>(n));
    if (n > 0) {
        cout << "Enter start and end times of activities:\n";
        for (int i = 0; i < n; i++) {
            if (!(cin >> activities[static_cast<size_t>(i)].start >> activities[static_cast<size_t>(i)].end) ||
                activities[static_cast<size_t>(i)].start < 0 ||
                activities[static_cast<size_t>(i)].end < 0 ||
                activities[static_cast<size_t>(i)].start >= activities[static_cast<size_t>(i)].end) {
                cerr << "Invalid activity times.\n";
                return 1;
            }
        }
    }
    int result = activitySelection(activities);
    cout << "Maximum number of non-overlapping activities: " << result << endl;
    return 0;
}