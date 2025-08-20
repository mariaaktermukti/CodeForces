
#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, ans = 0;
    cin >> n;
    vector<int> p(n);
    for(int i=0; i<n; i++) 
    {
        cin >> p[i];
    }
    for(int i=0; i<n; i++)
    {
        int left = 0, right = 0;
        for(int j=0; j<i; j++) if(p[j] > p[i]) left++;
        for(int j=i+1; j<n; j++) if(p[j] > p[i]) right++;
        ans += min(left, right);
    }
    cout << ans << '\n';
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