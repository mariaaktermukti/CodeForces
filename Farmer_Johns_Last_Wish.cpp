#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200000 + 5;
vector<int> divisors_of[MAXN];

void precalc_divisors()
{
    for (int d = 1; d < MAXN; ++d)
        for (int m = d; m < MAXN; m += d)
            divisors_of[m].push_back(d);
}

int main()
{
    precalc_divisors();

    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; ++i)
            cin >> a[i];

        vector<int> cnt(n + 1, 0);
        vector<char> is_full(n + 1, 0);
        vector<int> full_divs;
        int ans = 0;

        for (int i = 1; i <= n; ++i)
        {

            for (int d : divisors_of[a[i]])
            {
                if (d > n)
                    break;
                ++cnt[d];
            }

            vector<int> new_full;

            for (int d : divisors_of[a[i]])
            {
                if (d > n)
                    break;
                if (cnt[d] == i)
                {
                    if (!is_full[d])
                    {
                        is_full[d] = 1;
                        new_full.push_back(d);
                    }
                    else
                    {
                        new_full.push_back(d);
                    }
                }
                else
                {
                    ans = max(ans, cnt[d]);
                }
            }

            for (int d : full_divs)
            {
                if (!is_full[d])
                    continue;
                if (cnt[d] != i)
                {
                    ans = max(ans, cnt[d]);
                    is_full[d] = 0;
                }
                else
                {
                    new_full.push_back(d);
                }
            }

            full_divs.swap(new_full);
            cout << ans << (i == n ? '\n' : ' ');
        }
    }
    return 0;
}
