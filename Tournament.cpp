#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n, j, k;
        cin >> n >> j >> k;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
        }
        int strength_player_j = a[j - 1];
        int count_stronger_player = 0;
        for (int i = 0; i < n; i++) 
        {
            if (a[i] > strength_player_j) 
            {
                count_stronger_player++;
            }
        }
        if (count_stronger_player == 0 || k > 1) 
        {
            cout << "YES" << endl;
        } 
        else 
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}
