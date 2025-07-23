#include <bits/stdc++.h>
using namespace std;

const vector<int> coprimes = 
{
    1, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97,
    101, 103, 107, 109, 113, 121, 127, 131, 137, 139, 143, 149, 151, 157, 163, 167, 169,
    173, 179, 181, 187, 191, 193, 197, 199, 209
};

long long count_coprime_to_210(long long n) 
{
    long long complete_cycles = n / 210;
    long long remainder = n % 210;
    long long count = 0;
    for (int x : coprimes) 
    {
        if (x <= remainder) 
        {
            count++;
        } 
        else 
        {
            break;
        }
    }
    return 48LL * complete_cycles + count;
}

long long solve(long long l, long long r)
{
    return count_coprime_to_210(r) - count_coprime_to_210(l - 1);
}

int main() 
{
    int t;
    cin >> t; 
    while (t--) 
    {
        long long l, r;
        cin >> l >> r;
        cout << solve(l, r) << endl;
    }
    
    return 0;
}