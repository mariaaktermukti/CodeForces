#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        string t(n+1,'0');
        int ans = 0;
        int max_1 = 0;
        int max_2 = 0;
        for(int i = 0;i <= n/2-1;++i)
        {
            if(s[i] == s[n-i-1])
                max_2++;
            else
                ans++;
        }
        if(n%2 == 1)
            max_1++;
        for(int j = 0;j <= max_2;++j)
        {
            for(int k = 0;k <= max_1;++k)
            {
                t[ans + j*2 + k] = '1';
            }
        }
        cout << t << "\n";
    }
}