#include <bits/stdc++.h>
using namespace std;
 
void solve()
{
	int n, k;
	cin >> n >> k;
	int a[n];
	map<int, int> mp;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		mp[a[i]]++;
	}
	vector<int> c;
	for(auto x : mp)
	{
		if(x.second >= k)
		{
			c.push_back(x.first);
		}
	}
	if(c.size() == 0)
	{
		cout << -1 << endl;
		return;
	}
	sort(c.begin(), c.end());
	int mx = 0;
	int lans = c[0], rans = c[0];
	int l = c[0];
	for(int i = 1; i < c.size(); i++)
	{
		if(c[i]-1 == c[i-1])
		{
			if(c[i]-l > mx)
			{
				lans = l;
				rans = c[i];
				mx = c[i]-l;
			}
		}
		else
		{
			l = c[i];
		}
	}
	cout << lans << " " << rans << endl;
}

int main(int argc, char * argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		solve();
	}
}