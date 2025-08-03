#include<bits/stdc++.h>

using namespace std;

const int MOD = int(1e9) + 7;

int main() 
{
	int t; cin >> t;
	vector<int> ks(t);
	for (int _ = 0; _ < 2; _++)
		for (int i = 0; i < t; i++)
			cin >> ks[i];
	
	vector<int> ans(1 + *max_element(ks.begin(), ks.end()), 1);
	for (int i = 1; i < (int)ans.size(); i++)
		ans[i] = (2LL * ans[i - 1]) % MOD;
	
	for (int k : ks)
		cout << ans[k] << '\n';
	return 0;
}