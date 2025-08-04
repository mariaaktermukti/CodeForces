#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,x;
		cin>>n>>x;
		vector<long long>arr(n);
		long long sum=0;
		long long maximo=0;
		for(int k=0;k<n;k++)
		{
			cin>>arr[k];
			maximo=max(maximo,arr[k]);
			sum+=arr[k];
		}
		long long sec=(sum+x-1)/(long long)x;
		cout<<max(maximo,sec)<<endl;
	}
}