#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    int n;
    cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    const int BITS = 31; 
    vector<int> cnt(BITS, 0);
    for (ll x : a) 
    {
        for (int b = 0; b < BITS; b++) 
        {
            if (x & (1LL << b)) cnt[b]++;
        }
    }
    ll bestVal = -1;
    int bestIdx = 0;
    for (int i = 0; i < n; i++) 
    {
        ll mask = 0;
        for (int b = 0; b < BITS; b++) 
        {
            if ((a[i] & (1LL << b)) && cnt[b] == 1) 
            {
                mask |= (1LL << b);
            }
        }
        if (mask > bestVal) 
        {
            bestVal = mask;
            bestIdx = i;
        }
    }
    
    cout << a[bestIdx];
    for (int i = 0; i < n; i++) 
    {
        if (i == bestIdx) continue;
        cout << " " << a[i];
    }
    cout << '\n';

    return 0;
}
