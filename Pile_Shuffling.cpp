#include <bits/stdc++.h>
using namespace std;
using int64 = long long;

int main(){
    int T;
    if (scanf("%d", &T)!=1) 
    {
        return 0;
    }
    while (T--) 
    {
        int n;
        scanf("%d", &n);
        int64 ans = 0;
        for (int i = 0; i < n; i++) 
        {
            int64 a, b, c, d;
            scanf("%lld %lld %lld %lld", &a, &b, &c, &d);

            if (b > d) 
            {
                ans += (a + b - d);
            }
            else if (a > c) 
            {
                ans += (a - c);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
