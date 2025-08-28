#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        long long n, a, b;
        cin >> n >> a >> b;
        if (n % 2 != b % 2)
        {
            cout << "NO\n";
            continue;
        }
        if (a > b && (n % 2 != a % 2))
        {
            cout << "NO\n";
            continue;
        }
        cout << "YES\n";
    }
    return 0;
}
