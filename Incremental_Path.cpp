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

        string s;
        cin >> s;

        set<long long> black;

        for (int i = 0; i < m; i++)
        {
            long long x;
            cin >> x;
            black.insert(x);
        }

        long long cur = 1;

        for (char c : s)
        {
            cur++;

            if (c == 'B')
            {
                while (black.count(cur))
                    cur++;
            }

            black.insert(cur);

            if (c == 'B')
            {
                while (black.count(cur))
                    cur++;
            }
        }

        cout << black.size() << "\n";
        for (auto x : black)
            cout << x << " ";
        cout << "\n";
    }

    return 0;
}
