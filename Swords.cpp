#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int gcd(int a, int b) 
{
    while (a != 0 && b != 0) 
    {
        if (a > b) a %= b;
        else b %= a;
    }
    return max(a, b);
}

int main() 
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    ll sum = 0;
    int max_val = 0;

    for (int i = 0; i < n; i++) 
    {
        cin >> a[i];
        sum += a[i];
        max_val = max(max_val, a[i]);
    }

    int g = max_val - a[0];
    for (int i = 1; i < n; i++) 
    {
        g = gcd(g, max_val - a[i]);
    }

    ll moves = (1LL * max_val * n - sum) / g;
    cout << moves << " " << g << endl;

    return 0;
}
