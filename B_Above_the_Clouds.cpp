#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) 
    {
        int n;
        string s;
        cin >> n >> s;
        vector<int> right(26, 0);
        for (char ch : s) 
        {
            right[ch - 'a']++;
        }

        vector<int> left(26, 0);

        bool found = false;
        for (int i = 0; i < n; i++) 
        {
            right[s[i] - 'a']--;

            if (i > 0 && i < n - 1) 
            {
                int currentChar = s[i] - 'a';
                if (left[currentChar] > 0 || right[currentChar] > 0) 
                {
                    found = true;
                    break;
                }
            }

            left[s[i] - 'a']++;
        }

        if (found) 
        {
            cout << "Yes" << endl;
        } 
        else 
        {
            cout << "No" << endl;
        }
    }

    return 0;
}
