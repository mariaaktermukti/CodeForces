#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long x;
    int n;
    cin >> x >> n;

    set<long long> positions;
    positions.insert(0);
    positions.insert(x);

    multiset<long long> segs;
    segs.insert(x);

    vector<long long> answer;
    answer.reserve(n);

    for (int i = 0; i < n; i++) {
        long long p;
        cin >> p;
        auto it_right = positions.upper_bound(p);
        auto it_left = prev(it_right);

        long long left = *it_left;
        long long right = *it_right;
        long long old_len = right - left;

        auto mit = segs.find(old_len);
        segs.erase(mit);

        segs.insert(p - left);
        segs.insert(right - p);

        positions.insert(p);

        answer.push_back(*segs.rbegin());
    }

    for (int i = 0; i < n; i++) {
        cout << answer[i] << (i + 1 < n ? ' ' : '\n');
    }

    return 0;
}
