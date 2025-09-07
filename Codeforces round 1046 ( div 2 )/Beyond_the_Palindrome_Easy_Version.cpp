#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int MAXN = 1e6 + 10;
const int mod = 998244353;

inline int add(int x, int y) { return x += y, x < mod ? x : x - mod; }
inline int sub(int x, int y) { return x -= y, x < 0 ? x + mod : x; }
inline void cadd(int &x, int y) { x += y, x < mod || (x -= mod); }
inline void csub(int &x, int y) { x -= y, x < 0 && (x += mod); }

int inv[MAXN], a[MAXN], s[MAXN];

inline void init(int n)
{
    inv[1] = 1;
    for (int i = 2; i <= n; i++)
        inv[i] = (ll)(mod - mod / i) * inv[mod % i] % mod;
}

int n;

inline int ask(int l, int r)
{
    l = max(l, 0), r = min(r, n);
    return l ? sub(s[r], s[l - 1]) : s[r];
}

inline int calc(int k, int t)
{
    int sum = 0;
    for (int p = 0; (n + k >> 1) - p * (k + 2 - t) >= 0; p++)
    {
        cadd(sum, ask((n - k >> 1) - p * (k + 2 - t), (n + k >> 1) - t - p * (k + 2 - t)));
    }
    for (int p = 0; (n - k >> 1) - 1 - p * (k + 2 - t) >= 0; p++)
    {
        csub(sum, (ll)(k + 1 - t) * a[(n - k >> 1) - 1 - p * (k + 2 - t)] % mod);
    }
    for (int p = 1; (n - k >> 1) + p * (k + 2 - t) <= n; p++)
    {
        cadd(sum, ask((n - k >> 1) + p * (k + 2 - t), (n + k >> 1) - t + p * (k + 2 - t)));
    }
    for (int p = 0; (n + k >> 1) + 1 - t + p * (k + 2 - t) <= n; p++)
    {
        csub(sum, (ll)(k + 1 - t) * a[(n + k >> 1) + 1 - t + p * (k + 2 - t)] % mod);
    }
    return sum;
}

int T, ans;

int main()
{
    for (scanf("%d", &T), init(1e6 + 1); T--;)
    {
        scanf("%d", &n), *a = *s = 1, ans = 0;
        for (int i = 1, x = 1; i <= n; i++)
        {
            a[i] = (ll)a[i - 1] * inv[i] % mod * (n - i + 1) % mod;
            s[i] = add(s[i - 1], a[i]);
        }
        for (int i = 1, x = 0, y = 0; i <= n; i++)
        {
            if (n + i & 1)
                continue;
            cadd(ans, x), cadd(ans, x = calc(i, 0));
            y = calc(i, 1), csub(ans, add(y, y));
        }
        printf("%d\n", ans);
    }
}