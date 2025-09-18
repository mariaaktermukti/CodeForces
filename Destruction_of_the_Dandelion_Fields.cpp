#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int64> odds;
        int64 sumEven = 0;
        for (int i = 0; i < n; ++i)
        {
            int64 a;
            cin >> a;
            if (a % 2 == 0)
                sumEven += a;
            else
                odds.push_back(a);
        }
        if (odds.empty())
        {
            cout << 0 << '\n';
            continue;
        }
        sort(odds.begin(), odds.end(), greater<int64>());
        int take = (int)((odds.size() + 1) / 2);
        int64 sumOddCuts = 0;
        for (int i = 0; i < take; ++i)
            sumOddCuts += odds[i];
        cout << sumEven + sumOddCuts << '\n';
    }
    return 0;
}
