#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    for (int i = 0; i < n; ++i)
    {
        if (s[i] == '1')
        {
            int j = i;
            while (j + 1 < n && s[j + 1] == '1')
                ++j;
            if (j - i + 1 >= k)
            {
                cout << "NO\n";
                return;
            }
            i = j;
        }
    }

    cout << "YES\n";
    int cnt1 = count(s.begin(), s.end(), '1');
    int next1 = 1, next0 = cnt1 + 1;
    for (int i = 0; i < n; ++i)
    {
        if (i)
            cout << ' ';
        if (s[i] == '1')
            cout << next1++;
        else
            cout << next0++;
    }
    cout << '\n';
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}
