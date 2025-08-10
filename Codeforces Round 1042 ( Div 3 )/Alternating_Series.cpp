#include <bits/stdc++.h>
using namespace std;

void makearray(int position, int n, vector<long long>& result) {
    if (position == n) return; 
    if (position % 2 == 0) 
    {
        result[position] = -1;
    } 
    else 
    {   
        if (position == n - 1) 
        {
            result[position] = 2;
        } 
        else 
        {
            result[position] = 3;
        }
    }

    makearray(position + 1, n, result);
}

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<long long> ans(n);
        makearray(0, n, ans); 
        for (int i = 0; i < n; ++i) 
        {
            if (i) cout << ' ';
            cout << ans[i];
        }
        cout << endl;
    }
    return 0;
}
