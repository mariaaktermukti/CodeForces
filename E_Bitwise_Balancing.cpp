#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
void solve() 
{
    ll a = 0, b, c, d, pos = 1, bit_b, bit_c, bit_d, mask = 1;
    cin >> b >> c >> d;
    for (ll i = 0; i < 62; i++) 
    {
        if (b&mask) bit_b = 1;
        else bit_b = 0;
        if (c&mask) bit_c = 1;
        else bit_c = 0;
        if (d&mask) bit_d = 1;
        else bit_d = 0;
        if ((bit_b && (!bit_c) && (!bit_d)) || ((!bit_b) && bit_c && bit_d)) 
        {
            pos = 0;
            break;
        }
        if (bit_b && bit_c) 
        {
            a += (1ll-bit_d)*mask;
        } 
        else 
        {
            a += bit_d*mask;
        }
        mask<<=1;
    }
    if (pos) 
    {
        cout << a << "\n";
    } 
    else 
    {
        cout << -1 << "\n";
    }
}
 
int main() 
{
    ll t;
    cin >> t;
    while (t--) 
    {
        solve();
    }
}