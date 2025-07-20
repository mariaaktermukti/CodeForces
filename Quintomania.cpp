#include <bits/stdc++.h>
using namespace std;
 
bool solve()
{
    int n;
    cin >> n;
    vector<int>a(n);
    for(int i = 0; i < n; i++) 
    {
        cin >> a[i];
    }
    for(int i = 1; i < n; i++) 
    {
        if(abs(a[i] - a[i - 1]) != 5 && abs(a[i] - a[i - 1]) != 7) 
        {
            return false;
        }
    }
    return true;
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