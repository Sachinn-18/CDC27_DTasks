#include <bits/stdc++.h>
using namespace std;

class SegmentTreeLazy {
private:
    vector<long long> tree, lazy;
    int n;

    void build(int node, int start, int end, const vector<int>& arr) {
        if (start == end) {
            tree[node] = arr[start];
            return;
        }
        int mid = (start + end) / 2;
        build(2 * node, start, mid, arr);
        build(2 * node + 1, mid + 1, end, arr);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    void propagate(int node, int start, int end) {
        if (lazy[node] != 0) {
            tree[node] += (end - start + 1) * lazy[node];
            if (start != end) {
                lazy[2 * node] += lazy[node];
                lazy[2 * node + 1] += lazy[node];
            }
            lazy[node] = 0;
        }
    }

    void updateRange(int node, int start, int end, int l, int r, long long val) {
        propagate(node, start, end);
        if (start > end || start > r || end < l) return;
        if (l <= start && end <= r) {
            lazy[node] += val;
            propagate(node, start, end);
            return;
        }
        int mid = (start + end) / 2;
        updateRange(2 * node, start, mid, l, r, val);
        updateRange(2 * node + 1, mid + 1, end, l, r, val);
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    long long queryRange(int node, int start, int end, int l, int r) {
        propagate(node, start, end);
        if (start > end || start > r || end < l) return 0;
        if (l <= start && end <= r) return tree[node];
        int mid = (start + end) / 2;
        long long p1 = queryRange(2 * node, start, mid, l, r);
        long long p2 = queryRange(2 * node + 1, mid + 1, end, l, r);
        return p1 + p2;
    }

public:
    SegmentTreeLazy(const vector<int>& arr) {
        n = arr.size();
        tree.assign(4 * n, 0);
        lazy.assign(4 * n, 0);
        build(1, 0, n - 1, arr);
    }

    void updateRange(int l, int r, long long val) {
        updateRange(1, 0, n - 1, l, r, val);
    }

    long long queryRange(int l, int r) {
        return queryRange(1, 0, n - 1, l, r);
    }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    SegmentTreeLazy stl(arr);

    cout << "Initial sum of range [1, 3]: " << stl.queryRange(1, 3) << endl; // 3 + 5 + 7 = 15
    cout << "Initial sum of range [0, 5]: " << stl.queryRange(0, 5) << endl; // 1 + 3 + 5 + 7 + 9 + 11 = 36

    stl.updateRange(1, 3, 2); // Add 2 to range [1, 3]
    cout << "After range update, sum of range [1, 3]: " << stl.queryRange(1, 3) << endl; // (3+2) + (5+2) + (7+2) = 5 + 7 + 9 = 21

    stl.updateRange(0, 2, -1); // Subtract 1 from range [0, 2]
    cout << "After another range update, sum of range [0, 2]: " << stl.queryRange(0, 2) << endl; // (1-1) + (5-1) + (7-1) = 0 + 4 + 6 = 10

    return 0;
}
