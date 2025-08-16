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
        cin >> n;
        vector<long long> a(n);
        for (auto &x : a)
            cin >> x;

        unordered_map<long long, int> freq;
        freq.reserve(n * 2);
        for (auto x : a)
            ++freq[x];

        bool ok = false;
        for (auto &kv : freq)
        {
            if (kv.second >= 4)
            {
                ok = true;
                break;
            }
        }

        if (!ok)
        {
            vector<long long> d;
            d.reserve(freq.size());
            for (auto &kv : freq)
                d.push_back(kv.first);
            sort(d.begin(), d.end());

            int cnt2_in_block = 0;
            for (int i = 0; i < (int)d.size();)
            {
                int j = i;
                cnt2_in_block = 0;
                while (j < (int)d.size() && (j == i || d[j] == d[j - 1] + 1))
                {
                    if (freq[d[j]] >= 2)
                        ++cnt2_in_block;
                    ++j;
                }
                if (cnt2_in_block >= 2)
                {
                    ok = true;
                    break;
                }
                i = j;
            }
        }

        cout << (ok ? "Yes" : "No") << '\n';
    }
    return 0;
}
