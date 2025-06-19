#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t; 

    while (t--) 
    {
        int n;
        cin >> n;

        int a[n];
        int zeroCount = 0;
        int sum = 0;

        for (int i = 0; i < n; ++i) 
        {
            cin >> a[i];
            if (a[i] == 0) zeroCount++;
            sum += a[i];
        }

        if ((sum + zeroCount) == 0) 
        {
            cout << zeroCount + 1 << endl;
        } 
        else 
        {
            cout << zeroCount << endl;
        }
    }

    return 0;
}
