#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    int T;
    cin >> T;
    while (T--) 
    {
        int n;
        cin >> n;
        string sa, sb;
        cin >> sa >> sb;

        vector<int> a(n+1), b(n+1);
        for (int i = 1; i <= n; i++) a[i] = sa[i-1] - '0';
        for (int i = 1; i <= n; i++) b[i] = sb[i-1] - '0';

        vector<int> a0(n+1,0), a1(n+1,0);
        vector<int> b0(n+1,0), b1(n+1,0);

        for (int i = 1; i <= n; i++) 
        {
            a0[i] = a0[i-1] + (a[i] == 0);
            a1[i] = a1[i-1] + (a[i] == 1);
            b0[i] = b0[i-1] + (b[i] == 0);
            b1[i] = b1[i-1] + (b[i] == 1);
        }

        int offset = n;
        vector<ll> pref0(2*n+2,0), pref1(2*n+2,0);
        vector<int> count(2*n+2,0);

        for (int i = 1; i <= n; i++) 
        {
            int diff = a0[i] - a1[i];
            pref0[offset + diff] += a0[i];
            pref1[offset + diff] += a1[i];
            count[offset + diff]++;
        }
        for (int i = 1; i <= 2*n; i++) 
        {
            pref0[i] += pref0[i-1];
            pref1[i] += pref1[i-1];
            count[i] += count[i-1];
        }

        ll ans = 0;
        for (int i = 1; i <= n; i++) 
        {
            int z = b1[i] - b0[i];

            ans += (ll)b0[i] * count[offset + z] + pref0[offset + z];
            ans += (ll)b1[i] * (n - count[offset + z]) + (pref1[2*n] - pref1[offset + z]);
        }
        cout << ans << "\n";
    }
    return 0;
}
