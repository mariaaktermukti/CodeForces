#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
        }
        ll max_ele = a[n-1];
        ll valid_ways = 0;
        for (int k = 2; k < n; k++) 
        {
            ll red3 = a[k];
            ll mini_req_sum = max(red3, max_ele - red3);
            for (int j = 1; j < k; j++) 
            {
                ll need = mini_req_sum - a[j] + 1;
                auto it = lower_bound(a.begin(), a.begin() + j, need);
                valid_ways = valid_ways + (a.begin() + j) - it;
            }
        }
        cout << valid_ways << endl;
    }
    return 0;
}
