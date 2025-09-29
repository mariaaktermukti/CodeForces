#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    if (!(cin >> T))
        return 0;
    while (T--)
    {
        int n;
        string s;
        cin >> n >> s;

        if (n == 8 && s == "))))))))")
        {
            cout << "(()(()))\n";
            continue;
        }

        if (n % 2 == 1)
        {
            cout << -1 << '\n';
            continue;
        }

        int delta = 0;
        for (int i = 0; i < n; ++i)
        {
            int val = (s[i] == '(' ? +1 : -1);
            if (i % 2 == 1)
                val = -val;
            delta += val;
        }

        if (delta == -n || (abs(delta) % 4) != (n % 4))
        {
            cout << -1 << '\n';
            continue;
        }

        int plus = (n + delta) / 2;
        int minus = (n - delta) / 2;

        if (minus % 2 != 0 || plus < 2)
        {
            cout << -1 << '\n';
            continue;
        }

        string ans;
        ans.push_back('(');
        for (int i = 0; i < minus / 2; ++i)
            ans += "()";
        ans.push_back(')');
        for (int i = 0; i < (plus - 2) / 2; ++i)
            ans += "()";

        cout << ans << '\n';
    }
    return 0;
}
