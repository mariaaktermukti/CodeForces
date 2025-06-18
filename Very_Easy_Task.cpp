#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n;
    ll x, y;
    cin >> n >> x >> y;

    if (n == 0) 
    {
        cout << 0 << "\n";
        return 0;
    }
    if (n == 1) 
    {
        cout << min(x, y) << "\n";
        return 0;
    }

    ll first = min(x, y);
    ll need = n - 1;
    ll lo = 0, hi = need * min(x, y), ans = hi;
    while (lo <= hi) 
    {
        ll mid = lo + (hi - lo) / 2;
        ll produced = mid / x + mid / y;
        if (produced >= need) 
        {
            ans = mid;
            hi = mid - 1;
        } 
        else 
        {
            lo = mid + 1;
        }
    }
    cout << (first + ans) << endl;
    return 0;
}
