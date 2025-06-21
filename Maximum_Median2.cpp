#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main() 
{
    int n;
    ll k;
    cin >> n >> k;
    vector<ll> a(n);
    for(int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int mid = n / 2;
    ll left = a[mid], right = a[mid] + k + 1;

    while(left < right) 
    {
        ll m = (left + right) / 2;
        ll cost = 0;
        for(int i = mid; i < n; i++) 
        {
            if(a[i] < m) cost += (m - a[i]);
        }

        if(cost <= k) 
        {
            left = m + 1;
        } 
        else 
        {
            right = m;
        }
    }

    cout << left - 1 << endl;

    return 0;
}
