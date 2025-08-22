#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long k;
        cin >> k;
        long long cur = 9, len = 1;
        while (k - cur * len > 0)
        {
            k -= cur * len;
            cur *= 10;
            len++;
        }
        string s = to_string(cur / 9 + (k - 1) / len);
        long long ans = 0;
        for (int i = 0; i < (k - 1) % len + 1; i++)
            ans += s[i] - '0';
        long long pr_s = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int curd = s[i] - '0';
            if (curd)
                ans += curd * (len - 1) * cur / 2 + curd * (2 * pr_s + curd - 1) / 2 * cur / 9;
            cur /= 10, len--;
            pr_s += curd;
        }
        cout << ans << '\n';
    }

    return 0;
}