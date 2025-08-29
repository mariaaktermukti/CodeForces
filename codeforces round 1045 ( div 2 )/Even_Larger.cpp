#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> a(n);
        for (auto &i : a)
            cin >> i;

        vector<long long> b(n + 1, 0);
        long long ans = 0;
        for (int i = 0; i < n; i += 2)
        {
            long long mn = a[i];
            if (i >= 2)
                mn = min(mn, a[i - 1] - b[i - 2]);
            if (i + 1 < n)
                mn = min(mn, a[i + 1]);

            b[i] = mn;
            ans += (a[i] - b[i]);
        }

        cout << ans << '\n';
    }
}
