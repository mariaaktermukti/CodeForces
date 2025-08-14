#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--) 
    {
        long long a, b, x, y;
        cin >> a >> b >> x >> y;

        if (b < a) 
        {
            if ((a ^ 1) == b) 
            {
                cout << y << "\n";
            } 
            else 
            {
                cout << -1 << "\n";
            }
            continue;
        }

        long long d = b - a;

        if (x <= y) 
        {
            cout << d * x << "\n";
        } 
        else 
        {
            if (a % 2 == 0) 
            {
                long long ans = ((d + 1) / 2) * min(x, y) + (d / 2) * x;
                cout << ans << "\n";
            } 
            else 
            {
                long long ans = (d / 2) * min(x, y) + ((d + 1) / 2) * x;
                cout << ans << "\n";
            }
        }
    }
    return 0;
}
