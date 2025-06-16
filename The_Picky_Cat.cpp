#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) 
        {
            cin >> a[i];
        }

        vector<pair<int,int>> pairs;
        pairs.reserve(n);
        for (int i = 0; i < n; ++i) 
        {
            pairs.emplace_back(abs(a[i]), i);
        }

        sort(pairs.begin(), pairs.end());

        vector<int> ans(n, 0);
        int limit = n / 2 + 1;
        for (int i = 0; i < limit; ++i) 
        {
            int idx = pairs[i].second;
            ans[idx] = 1;
        }
        if (ans[0]) {
            cout << "YES\n";
        } 
        else 
        {
            cout << "NO\n";
        }
    }

    return 0;
}
