#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef long long ll;
int main() 
{
    string recipe;
    cin >> recipe;

    ll nb, ns, nc;
    cin >> nb >> ns >> nc;

    ll pb, ps, pc;
    cin >> pb >> ps >> pc;

    ll r;
    cin >> r;
    ll reqB = 0, reqS = 0, reqC = 0;
    for (char ch : recipe) 
    {
        if (ch == 'B') reqB++;
        else if (ch == 'S') reqS++;
        else if (ch == 'C') reqC++;
    }
    ll low = 0, high = 1e13, ans = 0;
    while (low <= high) 
    {
        ll mid = (low + high) / 2;

        ll needB = max(0LL, mid * reqB - nb);
        ll needS = max(0LL, mid * reqS - ns);
        ll needC = max(0LL, mid * reqC - nc);

        ll cost = needB * pb + needS * ps + needC * pc;

        if (cost <= r) 
        {
            ans = mid;
            low = mid + 1;  
        } 
        else {
            high = mid - 1;  
        }
    }

    cout << ans << endl;
    return 0;
}
