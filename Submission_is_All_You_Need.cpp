#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
        }
        
        ll score = 0;
        for (int x : a) {
            if (x == 0) 
            {
                score += 1;  
            } 
            else 
            {
                score += x; 
            }
        }
        
        cout << score << '\n';
    }
    return 0;
}