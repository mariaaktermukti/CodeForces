#include <iostream>

using namespace std;

const int MAXN = 10000001;
bool prime[MAXN];

void solve() 
{
    int n, ans = 0;
    cin >> n;
    
    for (int i = 2; i <= n; i++) 
    {
        if (prime[i]) 
        {
            ans += n / i;
        }
    }
    
    cout << ans << endl;
}

int main()
{
    for (int i = 0; i < MAXN; i++) prime[i] = 1;
    prime[0] = prime[1] = 0;
	for (int i = 2; i * i < MAXN; i++) 
    {
	    if (!prime[i]) continue;
	    for (int j = i * i; j < MAXN; j += i) 
            prime[j] = 0;
	}
	
    int t;
    cin >> t;
    while (t--) 
    {
        solve();
    }
}