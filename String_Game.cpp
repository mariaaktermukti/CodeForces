#include <bits/stdc++.h>
using namespace std;
int main() 
{
    int n, m, r;
    cin >> n >> m >> r;
    vector<int> s(n), b(m);
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    int best_buy = *min_element(s.begin(), s.end());
    int best_sell = *max_element(b.begin(), b.end());
\
    if (best_sell <= best_buy) 
    {
        cout << r;
    } 
    else 
    {
        int num_buy = r / best_buy;
        long long result = r + 1LL * num_buy * (best_sell - best_buy);
        cout << result;
    }
    return 0;
}
