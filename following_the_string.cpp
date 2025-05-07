#include <bits/stdc++.h>
using namespace std;

void solve() 
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    vector<int> cnt(26, 0);
    string s;
    s.reserve(n);
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < 26; j++) 
        {
            if (cnt[j] == a[i]) 
            {
                cnt[j]++;
                s.push_back(static_cast<char>('a' + j));
                break;
            }
        }
    }
    cout << s << '\n';
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) 
    {
        solve();
    }
    return 0;
}
