#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    cin >> n;
    vector<long long> p(n);
    for (int i = 0; i < n; i++) 
    {
        cin >> p[i];
    }

    sort(p.begin(), p.end());

    long long median = p[n / 2]; 

    long long total_cost = 0;
    for (int i = 0; i < n; i++) 
    {
        total_cost += abs(p[i] - median);
    }

    cout << total_cost << "\n";
    return 0;
}
