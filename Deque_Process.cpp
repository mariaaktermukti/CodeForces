#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; 
    cin >> T;
    while (T--) 
    {
        int N; cin >> N;
        vector<int> P(N);
        for (int &x : P) 
        {
            cin >> x;
        }
        string ans;
        int l = 0, r = N-1;
        for (int turn = 1; turn <= N; ++turn) 
        {
            bool takeLeft;
            if (turn % 2 == 1) takeLeft = P[l] < P[r];    
            else takeLeft = P[l] > P[r];        
            if (takeLeft) 
            {
                ans.push_back('L');
                ++l;
            } 
            else 
            {
                ans.push_back('R');
                --r;
            }
        }
        cout << ans << '\n';
    }
}