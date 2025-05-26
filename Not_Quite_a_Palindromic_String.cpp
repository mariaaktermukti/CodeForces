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
        long long n, k;
        cin >> n >> k;
        string s;
        cin >> s;

        long long count0 = 0, count1 = 0;
        for (char c : s) 
        {
            if (c == '0') count0++;
            else count1++;
        }
        long long pairs = n / 2;
        long long z = pairs - k;
        if (z < 0 || z > min(count0, count1)) 
        {
            cout << "NO";
        } 
        else 
        {
            long long rem0 = count0 - z;
            long long rem1 = count1 - z;
            if (rem0 % 2 == 0 && rem1 % 2 == 0) 
            {
                cout << "YES";
            } 
            else 
            {
                cout << "NO";
            }
        }
        cout << '\n';
    }

    return 0;
}