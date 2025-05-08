#include<bits/stdc++.h>
using namespace std;
 
void solve()
{
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0; i < n; i++) a[i] = n - i;
	reverse(a.end() - k - 1, a.end());
	for(int i = 0; i < n; i++)
	{
		if(i) cout << " ";
		cout << a[i];
	}
	cout << endl;
}
 
int main()
{
	int t;
	cin >> t;
	for(int i = 0; i < t; i++)
		solve();
	return 0;
}