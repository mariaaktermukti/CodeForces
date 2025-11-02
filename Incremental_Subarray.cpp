#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for (int i = 0; i < m; i++)
            cin >> a[i];

        bool drop = false;
        for (int i = 0; i < m - 1; i++)
        {
            if (a[i] >= a[i + 1])
            {
                drop = true;
                break;
            }
        }

        if (drop)
        {
            cout << 1 << "\n";
        }
        else
        {
            int r = a[m - 1];
            cout << n - r + 1 << "\n";
        }
    }
    return 0;
}
