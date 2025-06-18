#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<string> board(N);
    for (int i = 0; i < N; i++)
        cin >> board[i];

    vector<pair<int,int>> off = {
        {0,0}, {1,-1}, {1,0}, {1,1}, {2,0}
    };

    for (int r = 0; r + 2 < N; r++) 
    {
        for (int c = 1; c + 1 < N; c++) 
        {
            bool can = true;
            for (auto [dr,dc] : off) 
            {
                int rr = r + dr, cc = c + dc;
                if (board[rr][cc] != '.') 
                {
                    can = false;
                    break;
                }
            }
            if (can) 
            {
                for (auto [dr,dc] : off)
                    board[r+dr][c+dc] = '#';
            }
        }
    }
    for (int i = 0; i < N; i++) 
    {
        if (board[i].find('.') != string::npos) 
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}
