#include <bits/stdc++.h>
using namespace std;
 
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,r;
		cin>>n>>r;
		vector<int>arr(n);
		int left_alone=0;
		int happy=0;
		for(int k=0;k<n;k++)
		{
			cin>>arr[k];
			happy+=(arr[k]/2)*2;
			r-=arr[k]/2;
			left_alone+=arr[k]%2;
		}
		if(left_alone>r)
			happy+=r*2-left_alone;
		else
		 	happy+=left_alone;
		cout<<happy<<endl;
	}
}