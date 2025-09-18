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

        long long tmp;
        for (int i = 0; i < n; i++)
            cin >> tmp;
        for (int j = 0; j < m; j++)
            cin >> tmp;

        cout << n + m << "\n";
    }
    return 0;
}
