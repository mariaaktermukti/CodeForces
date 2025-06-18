#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n, s;
        cin >> n >> s;
        vector<int> x(n);
        for (int i = 0; i < n; i++) 
        {
            cin >> x[i];
        }
        sort(x.begin(), x.end());

        int Left = x.front();
        int Right = x.back();
        int Range = Right - Left;
        int distToLeft = abs(s - Left);
        int distToRight = abs(s - Right);
        int Ans = Range + min(distToLeft, distToRight);
        cout << Ans << endl;
    }

    return 0;
}
