#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) 
    {
        cin >> b[i];
    }

    vector<pair<int,int>> seg;
    long long ans = 0;

    for (int i = 0; i < n; i++) 
    {
        int l = min(a[i], b[i]);
        int r = max(a[i], b[i]);
        seg.push_back({l, r});
        ans += r - l;
    }

    sort(seg.begin(), seg.end());

    for (int i = 1; i < n; i++) 
    {
        if (seg[i].first <= seg[i-1].second) 
        {
            cout << ans << "\n";
            return;
        }
    }

    int min_gap = INT_MAX;
    for (int i = 1; i < n; i++) 
    {
        min_gap = min(min_gap, seg[i].first - seg[i-1].second);
    }

    cout << ans + 2LL * min_gap << "\n";
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        solve();
    }
}
