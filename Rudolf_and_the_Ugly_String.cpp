#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<string> patterns = {"mapie", "pie", "map"};

    while (t--) 
    {
        int n;
        string s;
        cin >> n >> s;
        int count = 0;
        for (const string& pat : patterns) 
        {
            size_t pos = s.find(pat);
            while (pos != string::npos) 
            {
                s[pos + pat.size() / 2] = '?';
                count++;
                pos = s.find(pat, pos + 1);
            }
        }

        cout << count << "\n";
    }

    return 0;
}
