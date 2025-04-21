#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t; 

    while (t--) {
        long long n;
        cin >> n;
        long long ans = 1;

        while (n > 3) {
            ans *= 2;
            n /= 4;
        }

        cout << ans << endl;
    }
    return 0;
}
