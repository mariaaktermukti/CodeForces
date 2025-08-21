#include <bits/stdc++.h>
using namespace std;

long long my_lcm(long long x, long long y)
{
    return x / __gcd(x, y) * y;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> p(n + 1), s(n + 1), a(n + 1);

        for (int i = 1; i <= n; i++)
            cin >> p[i];
        for (int i = 1; i <= n; i++)
            cin >> s[i];

        for (int i = 1; i <= n; i++)
        {
            a[i] = my_lcm(p[i], s[i]);
        }

        bool ok = true;
        long long g = 0;
        for (int i = 1; i <= n; i++)
        {
            g = __gcd(g, a[i]);
            if (g != p[i])
            {
                ok = false;
                break;
            }
        }

        g = 0;
        for (int i = n; i >= 1; i--)
        {
            g = __gcd(g, a[i]);
            if (g != s[i])
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }

    return 0;
}
