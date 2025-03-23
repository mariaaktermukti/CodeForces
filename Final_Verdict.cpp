#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) 
    {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        bool inArray = false;
        for(int val : a)
        {
            if(val == x)
            {
                inArray = true;
                break;
            }
        }

        long long sumA = 0;
        for(int val : a)
        {
            sumA += val;
        }
        bool isGlobalAvg = (sumA == 1LL * x * n);

        if(inArray || isGlobalAvg) 
        {
            cout << "YES\n";
        } 
        else 
        {
            cout << "NO\n";
        }
    }
    return 0;
}
