#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        ll k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
        }
        vector<bool> seen(n + 1, false);
        for (int x : a) {
            if (x <= n) seen[x] = true;
        }
        int mex = 0;
        while (mex <= n && seen[mex]) 
        {
            mex++;
        }

        vector<int> b(n + 1);
        for (int i = 0; i < n; i++) 
        {
            b[i] = a[i];
        }
        b[n] = mex;

        ll len = n + 1;
        ll r = k % len;
        vector<int> res(n);
        for (int i = 0; i < n; i++) 
        {
            int idx = (int)((i - r + len) % len);
            res[i] = b[idx];
        }

        for (int i = 0; i < n; i++) 
        {
            cout << res[i] << (i + 1 < n ? ' ' : '\n');
        }
    }

    return 0;
}
