#include<bits/stdc++.h>
using namespace std;

bool isPrime(int x)
{
	if(x <= 1)
		return 0;
	for(int i = 2 ; i * i <= x ; ++i)
		if(x % i == 0)
			return 0;
	return 1;
}

vector<int> generateSol(int n, int p)
{
	vector<int> ans;
	ans.push_back(p);
	for(int i = 1 ; i <= n ; ++i)
    {
		if(p - i > 0)
			ans.push_back(p - i);
		if(p + i <= n)
			ans.push_back(p + i);
	}
	return ans;
}

int main()
{
	int t;
	cin >> t;
	for(int i = 1 ; i <= t ; ++i)
    {
		int n;
		cin >> n;
		vector < int > ans;
		for(int x = 0 ; ; ++x){
			if(isPrime(n / 2 - x))
            {
				ans = generateSol(n , n / 2 - x);
				break;
			}
			if(isPrime(n / 2 + x))
            {
				ans = generateSol(n , n / 2 + x);
				break;
			}
		}
		for(int i = 0 ; i < n ; ++i)
			cout << ans[i] << " \n"[i == n - 1];
	}
	return 0;
}