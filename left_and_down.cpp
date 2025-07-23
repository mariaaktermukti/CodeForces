#include <bits/stdc++.h>

using namespace std;

long long gcd(long long x, long long y) 
{
    while (y != 0)
    {
        long long temp = y;
        y = x % y;
        x = temp;
    }
    return x;
}

int main() 
{
    int t;
    cin >> t; 

    for (int i = 0; i < t; i++) 
    {
        long long a, b, k;
        cin >> a >> b >> k; 

        long long g = gcd(a, b);

        long long ap = a / g; 
        long long bp = b / g; 

        if (k >= ap && k >= bp) 
        {
            cout << 1 << endl;
        } 
        else 
        {
            cout << 2 << endl;
        }
    }

    return 0;
}