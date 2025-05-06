#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> words(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> words[i];
    }
    unordered_set<string> seen;
    vector<string> result;

    for (int i = n - 1; i >= 0; i--) 
    {
        const string &w = words[i];
        if (!seen.count(w)) 
        {
            seen.insert(w);
            result.push_back(w.substr(w.size() - 2));
        }
    }

    for (const auto &suf : result) 
    {
        cout << suf;
    }
    cout << "\n";

    return 0;
}
