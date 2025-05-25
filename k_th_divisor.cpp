#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() 
{
    long long n;
    int k;
    cin >> n >> k;

    vector<long long> small_divisors, large_divisors;

    for (long long i = 1; i * i <= n; ++i) 
    {
        if (n % i == 0) 
        {
            small_divisors.push_back(i);
            if (i != n / i) 
            {
                large_divisors.push_back(n / i);
            }
        }
    }
    vector<long long> divisors = small_divisors;
    reverse(large_divisors.begin(), large_divisors.end());
    divisors.insert(divisors.end(), large_divisors.begin(), large_divisors.end());

    if (k > divisors.size()) 
    {
        cout << -1 << endl;
    } 
    else 
    {
        cout << divisors[k - 1] << endl; 
    }

    return 0;
}
