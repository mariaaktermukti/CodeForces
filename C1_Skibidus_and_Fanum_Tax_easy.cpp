#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--) 
    {
        int n, m;
        cin >> n >> m; 
        vector<long long> a(n);
        for(int i = 0; i < n; i++) 
        {
            cin >> a[i];
        }

        vector<long long> b(m);
        for(int j = 0; j < m; j++) 
        {
            cin >> b[j];
        }
        long long B = b[0];  

        vector<vector<bool>> dp(n, vector<bool>(2, false));
        dp[0][0] = true;
        dp[0][1] = true;

        for(int i = 1; i < n; i++) {
            if(dp[i-1][0] && a[i-1] <= a[i]) {
                dp[i][0] = true;
            }
            if(dp[i-1][1] && (B - a[i-1]) <= a[i]) {
                dp[i][0] = true;
            }
            if(dp[i-1][0] && a[i-1] <= (B - a[i])) {
                dp[i][1] = true;
            }
            if(dp[i-1][1] && (B - a[i-1]) <= (B - a[i])) {
                dp[i][1] = true;
            }
        }
        if(dp[n-1][0] || dp[n-1][1]) 
        {
            cout << "YES\n";
        } 
        else 
        {
            cout << "NO\n";
        }
    }

    return 0;
}
