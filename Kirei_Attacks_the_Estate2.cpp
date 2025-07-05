#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        vector<vector<int>> gr(n);
        for (int i = 0; i < n - 1; i++) {
            int v, u;
            cin >> v >> u;
            --v; --u;
            gr[v].push_back(u);
            gr[u].push_back(v);
        }
        vector<ll> res(n, 0);
        vector<tuple<int,int,ll,ll>> st;
        st.emplace_back(0, -1, 0LL, 0LL);
        while (!st.empty()) {
            auto [v, p, mini, maxi] = st.back();
            st.pop_back();
            ll without_parent = arr[v];
            ll with_parent = mini * -1 + arr[v];
            res[v] = max(without_parent, with_parent);
            ll new_mini = min(arr[v], maxi * -1 + arr[v]);
            ll new_maxi = res[v];
            for (int u : gr[v]) {
                if (u == p) continue;
                st.emplace_back(u, v, new_mini, new_maxi);
            }
        }
        for (int i = 0; i < n; i++) {
            cout << res[i] << (i + 1 < n ? ' ' : '\n');
        }
    }
    return 0;
}
