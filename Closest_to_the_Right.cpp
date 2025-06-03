#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];
    }

    while (k--) 
    {
        int x;
        cin >> x;
        auto it = lower_bound(a.begin(), a.end(), x);
        int idx = it - a.begin() + 1; 
        if (it == a.end()) idx = n + 1;
        cout << idx << '\n';
    }

    return 0;
}
