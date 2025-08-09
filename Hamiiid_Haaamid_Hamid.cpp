#include <bits/stdc++.h>
using namespace std;

int calculate_days(int gridSize, int hamidPos, const string &grid) 
{
    if (hamidPos == 1 || hamidPos == gridSize) 
        return 1;

    hamidPos--;
    int INF = 1e9;
    int nearestWallLeft = -INF, nearestWallRight = INF;

    for (int i = hamidPos - 1; i >= 0; i--) 
    {
        if (grid[i] == '#') 
        {
            nearestWallLeft = i;
            break;
        }
    }

    for (int i = hamidPos + 1; i < gridSize; i++) 
    {
        if (grid[i] == '#') 
        {
            nearestWallRight = i;
            break;
        }
    }

    if (nearestWallLeft == -INF && nearestWallRight == INF)
        return 1;

    return max(
        min(hamidPos + 1, gridSize - nearestWallRight + 1),
        min(nearestWallLeft + 2, gridSize - hamidPos)
    );
}

int main() 
{
    int testCases;
    cin >> testCases;
    while (testCases--) 
    {
        int gridSize, hamidPos;
        string grid;
        cin >> gridSize >> hamidPos >> grid;
        cout << calculate_days(gridSize, hamidPos, grid) << "\n";
    }
    return 0;
}
