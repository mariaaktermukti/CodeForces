#include <bits/stdc++.h>

using namespace std;

void solve(int tc)
{
    int n;
    cin >> n;
    int last = -1, ans = 0;
    for(int i = 0; i < n; ++i)
    {
        int a;
        cin >> a;
        if(a - last > 1)
        {
            ans++;
            last = a;
        }
    }
    cout << ans;
}

bool multi = true;

signed main() 
{
    int t = 1;
    if (multi)cin >> t;
    for (int i = 1; i <= t; ++i) 
    {
        solve(i);
        cout << "\n";
    }
    return 0;
}