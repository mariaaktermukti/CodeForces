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
        long long k;
        cin >> n >> k;
        vector<int> a(n);
        for (int i = 0; i < n; ++i)
            cin >> a[i];

        sort(a.begin(), a.end());
        vector<int> l;
        vector<int> sl;

        while (k > 0 && l != a)
        {
            --k;
            sl = l;
            l = a;

            vector<int> F(n + 2, 0);
            for (int x : a)
            {
                if (x >= 0 && x <= n)
                    F[x]++;
            }

            int mex = 0;
            while (mex < (int)F.size() && F[mex] > 0)
                ++mex;

            vector<int> B;
            B.reserve(n);
            int mm = 0;
            for (int x : a)
            {
                if (F[x] > 1)
                {
                    B.push_back(mex);
                }
                else
                {
                    B.push_back(mm);
                }
                if (x == mm)
                    ++mm;
            }

            sort(B.begin(), B.end());
            a = move(B);

            if (a == sl)
            {
                k &= 1LL;
            }
        }

        long long sum = 0;
        for (int x : a)
            sum += x;
        cout << sum << '\n';
    }
    return 0;
}
