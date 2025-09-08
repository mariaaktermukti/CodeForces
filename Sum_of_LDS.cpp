#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
    int nTests; 
    cin >> nTests;

    while (nTests--) 
    {
        int nVals; cin >> nVals;
        vector<int> vals(nVals);
        
        for (int& val : vals)
            cin >> val;

        int sum = (nVals * (nVals + 1) * (nVals + 2))/6;
        for (int i = 0; i + 1 < nVals; ++i) {
            if (vals[i] < vals[i + 1]) {
                sum -= (i + 1) * (nVals - i - 1);
            }
        }

        cout << sum << endl;
    }
    return 0;
}