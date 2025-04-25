#include <bits/stdc++.h>
using namespace std;

// Solve one query in O(log(r-l+1)) time
int solve_query(const vector<int>& p, int l, int r, int x) {
    // 1) Find the true position of x in p[l..r]
    int pos = -1;
    for (int i = l; i <= r; i++) {
        if (p[i] == x) {
            pos = i;
            break;
        }
    }
    if (pos == -1) return -1;  // x not present ⇒ impossible

    // 2) Simulate binary-search comparisons on [l..r]
    int d = 0;
    int lo = l, hi = r;
    while (true) {
        int m = (lo + hi) >> 1;
        if (m == pos) {
            // Found x
            break;
        }
        if (m < pos) {
            // Search would go right ⇒ need p[m] < x
            if (p[m] >= x) d++;
            lo = m + 1;
        } else {
            // m > pos ⇒ search goes left ⇒ need p[m] > x
            if (p[m] <= x) d++;
            hi = m - 1;
        }
    }
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) {
        int n, q;
        cin >> n >> q;
        vector<int> p(n+1);
        for (int i = 1; i <= n; i++) {
            cin >> p[i];
        }
        while (q--) {
            int l, r, x;
            cin >> l >> r >> x;
            cout << solve_query(p, l, r, x) << "\n";
        }
    }
    return 0;
}
