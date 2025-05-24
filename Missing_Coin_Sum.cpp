#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<long long> coins(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> coins[i];
    }

    sort(coins.begin(), coins.end());

    long long res = 1; 

    for (int i = 0; i < n; i++) 
    {
        if (coins[i] > res) 
        {
            break;
        }
        res += coins[i];
    }

    cout << res << "\n";

    return 0;
}
