#include <iostream>
using namespace std;

const int MOD = 1e9 + 7;

long long mod_pow(long long base, long long exp, int mod) 
{
    long long result = 1;
    base %= mod;
    while (exp > 0) 
    {
        if (exp % 2 == 1) result = (result * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

int main() 
{
    int n;
    cin >> n;
    while (n--) 
    {
        long long a, b;
        cin >> a >> b;
        if (a == 0 && b == 0)
            cout << 1 << '\n'; 
        else
            cout << mod_pow(a, b, MOD) << '\n';
    }
    return 0;
}
