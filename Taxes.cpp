#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(long long n) 
{
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (long long i = 3; i * i <= n; i += 2) 
    {
        if (n % i == 0) return false;
    }
    return true;
}

int main() 
{
    long long n;
    cin >> n;
    if (isPrime(n)) 
    {
        cout << 1 << endl;
    }
    else if (n % 2 == 0) 
    {
        cout << 2 << endl;
    }
    else if (isPrime(n - 2)) 
    {
        cout << 2 << endl;
    }
    else 
    {
        cout << 3 << endl;
    }

    return 0;
}
