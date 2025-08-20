#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> prefix_Min(n), suffix_Max(n);
        prefix_Min[0] = a[0];
        for(int i = 1; i < n; i++)
        {
            prefix_Min[i] = min(prefix_Min[i-1], a[i]);
        }
        suffix_Max[n-1] = a[n-1];
        for(int i = n-2; i >= 0; i--)
        {
            suffix_Max[i] = max(suffix_Max[i+1], a[i]);
        }

        string Answer(n, '0');
        for(int i = 0; i < n; i++)
        {
            if (a[i] == prefix_Min[i] || a[i] == suffix_Max[i]) Answer[i] = '1';      
        }

        cout << Answer << endl;
    }
    return 0;
}
