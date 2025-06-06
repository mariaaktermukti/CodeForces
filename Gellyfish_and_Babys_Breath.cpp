#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5, Mod = 998244353;
int n = 0, s[N] = {}, p[N] = {}, q[N] = {}, r[N] = {};

inline void solve(){
	scanf("%d", &n);
	for(int i = 0 ; i < n ; i ++) scanf("%d", &p[i]);
	for(int i = 0 ; i < n ; i ++) scanf("%d", &q[i]);
	for(int i = 0, j = 0, k = 0 ; k < n ; k ++){
		if(p[k] > p[i]) i = k; if(q[k] > q[j]) j = k;
		if(p[i] != q[j]){
			if(p[i] > q[j]) printf("%d ", (s[p[i]] + s[q[k - i]]) % Mod);
			else printf("%d ", (s[q[j]] + s[p[k - j]]) % Mod);
		}
		else printf("%d ", (s[p[i]] + s[max(q[k - i], p[k - j])]) % Mod);
	}
	printf("\n");
}

int T = 0;

int main(){
	s[0] = 1; for(int i = 1 ; i < N ; i ++) s[i] = s[i - 1] * 2 % Mod;
	scanf("%d", &T);
	while(T --) solve();
	return 0;
}