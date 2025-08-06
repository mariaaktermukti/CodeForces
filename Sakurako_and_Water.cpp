#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;

        vector<long long> minOnDiag(2 * n - 1, 0LL);

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                long long aij;
                cin >> aij;
                int diagIndex = (i - j) + (n - 1);
                minOnDiag[diagIndex] = min(minOnDiag[diagIndex], aij);
            }
        }

        long long ans = 0;
        for (long long v : minOnDiag) 
        {
            if (v < 0) 
            {
                ans = ans + -v;
            }
        }

        cout << ans << "\n";
    }
    return 0;
}
