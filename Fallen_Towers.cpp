#include <iostream>
#include <algorithm>
#include <cstring>
#define MAXN 100005
typedef long long ll;
ll a[MAXN], d[MAXN], n;
bool check(ll ans) 
{
    memset(d, 0, sizeof(ll) * n);
    ll acc = 0;

    for (ll i = 0; i < n; ++i) 
    {
        acc -= d[i];

        ll need = std::max(0LL, i - (n - ans));
        if (acc < need) return false;

        ll end = i + a[i] + (acc++) - need + 1;
        if (end < n) ++d[end]; 
    }

    return true;
}

void solve() 
{
    std::cin >> n;
    for (ll i = 0; i < n; ++i) std::cin >> a[i];

    ll left = 1, right = n + 1;
    while (right - left > 1) 
    {
        ll mid = (left + right) / 2;
        if (check(mid)) 
        {
            left = mid;
        } 
        else 
        {
            right = mid;
        }
    }

    std::cout << left << "\n";
}

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll t;
    std::cin >> t;
    while (t--) 
    {
        solve();
    }

    return 0;
}
