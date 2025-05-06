#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--) 
    {
        int n;
        string s;
        cin >> n >> s;

        bool ok = false;
        if (s.find("111") != string::npos) 
        {
            ok = true;
        }
        int cnt11 = 0;
        for (int i = 0; i + 1 < n; i++) 
        {
            if (s[i] == '1' && s[i + 1] == '1')
                cnt11++;
        }
        if (cnt11 >= 2) 
        {
            ok = true;
        }

        if (s.front() == '1' && s.back() == '1') 
        {
            ok = true;
        }
        if ((s.front() == '1' || s.back() == '1') && cnt11 >= 1) 
        {
            ok = true;
        }

        cout << (ok ? "Yes\n" : "No\n");
    }
    return 0;
}
