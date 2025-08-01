#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n, m;
        cin >> n >> m;

        int count = 0;
        int total_len = 0;
        bool stopped = false;

        for (int i = 0; i < n; ++i) 
        {
            string s;
            cin >> s;
            if (!stopped) 
            {
                int len = s.length();
                if (total_len + len <= m) 
                {
                    total_len += len;
                    ++count;
                } 
                else 
                {
                    stopped = true;
                }
            }
    
        }

        cout << count << "\n";
    }

    return 0;
}
