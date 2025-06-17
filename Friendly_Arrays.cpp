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
        ll n, m;
        cin >> n >> m;

        ll x = 0;      
        ll orb = 0;    

        for (ll i = 0; i < n; i++) 
        {
            ll ai;
            cin >> ai;
            x ^= ai;
        }
        for (ll j = 0; j < m; j++) 
        {
            ll bj;
            cin >> bj;
            orb |= bj;
        }
        ll min_x, max_x;
        if (n % 2 == 0) 
        {
            min_x = x & (~orb);
            max_x = x;
        } 
        else 
        {
            min_x = x;
            max_x = x | orb;
        }

        cout << min_x << " " << max_x << "\n";
    }

    return 0;
}
