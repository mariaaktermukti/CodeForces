#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }

    int totalMasks = 1 << n;  
    for (int mask = 0; mask < totalMasks; mask++) 
    {
        int angle = 0;
        for (int j = 0; j < n; j++) 
        {
            if (mask & (1 << j)) 
            {
                angle += a[j];  
            } 
            else 
            {
                angle -= a[j];  
            }
        }
        angle = (angle % 360 + 360) % 360;
        if (angle == 0) 
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}
