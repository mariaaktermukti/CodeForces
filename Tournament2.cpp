#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
    int n, j, k, mx = 0;
    cin >> n >> j >> k;
    vector<int> a(n+1);
    for(int i=1; i<=n; i++)
    {
        cin >> a[i];
        mx = max(mx, a[i]);
    }
    cout << (k > 1 || a[j] == mx ? "YES" : "NO") << '\n';
}
 
int main()
{
    int t;
    cin >> t;
    while(t--) 
    {
        solve();
    }
}