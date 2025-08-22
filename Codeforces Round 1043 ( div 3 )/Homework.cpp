#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        string a, b, c;
        cin >> n >> a;
        cin >> m >> b >> c;

        string add_left = "";

        for (int i = 0; i < m; ++i)
        {
            if (c[i] == 'V')
            {
                add_left += b[i];
            }
            else
            {
                a += b[i];
            }
        }

        reverse(add_left.begin(), add_left.end());
        cout << add_left + a << '\n';
    }

    return 0;
}
