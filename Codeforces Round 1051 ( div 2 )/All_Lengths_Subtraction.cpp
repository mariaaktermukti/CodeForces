#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> p(n + 1), pos(n + 1);
        for (int i = 1; i <= n; ++i)
        {
            cin >> p[i];
            pos[p[i]] = i;
        }

        int left = pos[n], right = pos[n];
        bool ok = true;
        for (int x = n - 1; x >= 1; --x)
        {
            if (pos[x] == left - 1)
            {
                left = pos[x];
            }
            else if (pos[x] == right + 1)
            {
                right = pos[x];
            }
            else
            {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << '\n';
    }

    return 0;
}
