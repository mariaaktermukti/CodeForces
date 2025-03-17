#include <iostream>
using namespace std;
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--)
    {
        long long n, k;
        cin >> n >> k;

        if(n % 2 == 0)
        {
            long long d = k - 1;
            long long ans = (n + d - 1) / d;
            cout << ans << "\n";
        } 
        else 
        {
            if(n <= k) 
            {
                cout << 1 << "\n";
            } 
            else 
            {
                long long d = k - 1;
                long long remainder = n - k;
                long long moves = (remainder + d - 1) / d;
                cout << 1 + moves << "\n";
            }
        }
    }
    return 0;
}
