#include <bits/stdc++.h>
using namespace std;

int countBits(int x) {
    return __builtin_popcount(x); 
}

int main() 
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> players(m + 1); 

    for (int i = 0; i <= m; ++i) 
    {
        cin >> players[i];
    }

    int fedorsArmy = players[m];
    int friends = 0;

    for (int i = 0; i < m; ++i) 
    {
        int diff = countBits(players[i] ^ fedorsArmy);
        if (diff <= k) 
        {
            ++friends;
        }
    }

    cout << friends << endl;
    return 0;
}
