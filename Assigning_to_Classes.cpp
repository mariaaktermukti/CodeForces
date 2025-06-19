#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) 
    {
        int n;
        cin >> n;
        vector<int> a(2 * n);
        for (int i = 0; i < 2 * n; ++i) 
        {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        cout << a[n] - a[n - 1] << "\n";
    }

    return 0;
}
