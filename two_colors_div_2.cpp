#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
 
    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> a(m);
        for(int i = 0; i < m; i++)
        {
            cin >> a[i];
        }
 
        vector<int> v(m);
        for (int i = 0; i < m; i++)
        {
            v[i] = min(a[i], n - 1);
        }
 
        vector<int> sorted = v;
        sort(sorted.begin(), sorted.end());
 
        vector<long long> prefix(m+1, 0);
        for (int i = 0; i < m; i++)
        {
            prefix[i+1] = prefix[i] + sorted[i];
        }
 
        auto getSum = [&](int T) -> long long 
        {
            int pos = lower_bound(sorted.begin(), sorted.end(), T) - sorted.begin();
            int count = m - pos;
            if(count <= 0) return 0LL;
            long long sumPart = prefix[m] - prefix[pos];
            return sumPart - (long long)(T - 1) * count;
        };

        long long ans = 0;
        for (int j = 0; j < m; j++)
        {
            int T;
            if(a[j] >= n) T = 1;
            else T = n - a[j];
 
            long long totalForT = getSum(T);
            if(v[j] >= T)
            {
                totalForT -= (long long)(v[j] - T + 1);
            }
            ans += totalForT;
        }
 
        cout << ans << "\n";
    }
    return 0;
}
