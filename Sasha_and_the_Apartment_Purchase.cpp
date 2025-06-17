#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        int m = n - k;
        if (m % 2 == 1) {
            int mid = m / 2;
            int start = mid;
            int end = mid + k;
            ll cnt = 0;
            ll last = LLONG_MIN;
            for (int i = start; i <= end; i++) {
                if (a[i] != last) {
                    cnt++;
                    last = a[i];
                }
            }
            cout << cnt << '\n';
        } else {
            int mid = m / 2;
            vector<pair<ll,ll>> segs;
            segs.reserve(k+1);
            for (int i = 0; i <= k; i++) {
                ll L = a[i + mid - 1];
                ll R = a[i + mid];
                segs.emplace_back(L, R);
            }
            sort(segs.begin(), segs.end());
            ll result = 0;
            ll curL = segs[0].first;
            ll curR = segs[0].second;
            for (int i = 1; i < segs.size(); i++) {
                auto &p = segs[i];
                if (p.first <= curR) {
                    curR = max(curR, p.second);
                } else {
                    result += (curR - curL + 1);
                    curL = p.first;
                    curR = p.second;
                }
            }
            result += (curR - curL + 1);
            cout << result << '\n';
        }
    }
    return 0;
}
