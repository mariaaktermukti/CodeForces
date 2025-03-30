#include <iostream>
#include <algorithm>
using namespace std;
 
typedef long long ll;
 
ll maxDesksInRow(ll m, ll T) 
{
    ll groups = (m + 1) / (T + 1);
    ll cand1 = T * groups;
    ll Q = m / (T + 1);
    ll rem = m - Q * (T + 1);
    ll cand2 = T * Q + min(T - 1, rem);
    
    return max(cand1, cand2);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        ll n, m, k;
        cin >> n >> m >> k;
        ll low = 1, high = m, ans = m;
        while(low <= high)
        {
            ll mid = (low + high) / 2;
            ll capacity = maxDesksInRow(m, mid);
            if(n * capacity >= k)
            {
                ans = mid;
                high = mid - 1;
            }
            else 
            {
                low = mid + 1;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
