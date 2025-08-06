#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        int x = 0;
        int move = 1;
        while (abs(x) <= n) 
        {
            int step = 2 * move - 1;
            if (move % 2 == 1) 
            {
                x = x - step;
            } 
            else 
            {
                x = x + step;
            }
            move++;
        }
        if ((move - 1) % 2 == 1) 
        {
            cout << "Sakurako\n";
        } 
        else 
        {
            cout << "Kosuke\n";
        }
    }

    return 0;
}
