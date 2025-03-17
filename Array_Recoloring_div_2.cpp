#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) 
    {
        int n, k;
        cin >> n >> k;
        vector<long long> a(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> a[i];
        }
        
        sort(a.begin(), a.end(), greater<long long>());
        
        long long cost = 0;
        for (int i = 0; i < k; i++) 
        {
            cost += a[i];
        }
        
        cost += a[k];
        
        cout << cost << "\n";
    }
    return 0;
}