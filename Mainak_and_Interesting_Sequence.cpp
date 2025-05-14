#include<bits/stdc++.h>
using namespace std;

inline void test_case()
{
	int N, M;
	cin >> N >> M;

	if(((N % 2 == 0) && (M % 2 == 1)) || (M < N))
    { 
		cout << "NO\n";
	}
    else if((N % 2) == 1)
    {
		cout << "YES\n";
		for(int i = 1; i < N; ++i)
        {
			cout << "1 ";
		}
		cout << M - N + 1 << '\n';
	}
    else
    { 
		cout << "YES\n";
		for(int i = 2; i < N; ++i)
        {
			cout << "1 ";
		}
		cout << (M - N + 2) / 2 << ' ' << (M - N + 2) / 2 << '\n';
	}

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test_case_number;
	cin>>test_case_number;
	while(test_case_number--)
		test_case();
	
	return 0;
}