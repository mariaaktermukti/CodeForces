#include<bits/stdc++.h>
using namespace std;

bool solve()
{
    int n, k;
    cin >> n >> k;
    vector<int>c(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    int left = 0, right = 0, i = 0, j = n - 1;
    int k_left = k, k_right = k;

    if (c[0] == c[n - 1])
    {
        k_left = k / 2;
        k_right = k - k_left;
    }
    for(; i < n && left < k_left; i++)
    {
        if(c[i] == c[0]) left++;
    }
    for(; j >= 0 && right < k_right; j--)
    {
        if(c[j] == c[n - 1]) right++;
    }
    return (i - 1) < (j + 1);
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cout << (solve() ? "YES" : "NO") << "\n";
    }

}