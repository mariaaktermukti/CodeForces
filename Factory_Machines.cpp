#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
bool isEnough(ll mid, const vector<ll>& machines, ll t) 
{
    ll total = 0;
    for (ll time : machines) 
    {
        total += mid / time;
        if (total >= t) return true; 
    }
    return false;
}

int main() 
{
    ll n, t;
    cin >> n >> t;

    vector<ll> machines(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> machines[i];
    }

    ll low = 1;
    ll high = 1e18; 
    ll answer = high;

    while (low <= high) {
        ll mid = low + (high - low) / 2;

        if (isEnough(mid, machines, t)) 
        {
            answer = mid;
            high = mid - 1; 
        } 
        else 
        {
            low = mid + 1; 
        }
    }

    cout << answer << endl;
    return 0;
}
