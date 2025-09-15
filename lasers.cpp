#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        long long x, y;
        cin >> n >> m >> x >> y;

        vector<long long> a(n), b(m);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        for (int j = 0; j < m; j++)
        {
            cin >> b[j];
        }

        cout << max(n, m) + 1 << "\n";
    }
    return 0;
}
