#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() 
{
    int n, x;
    cin >> n >> x;

    vector<int> weight(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> weight[i];
    }

    sort(weight.begin(), weight.end());

    int i = 0, j = n - 1;
    int gondolas = 0;

    while (i <= j) {
        if (weight[i] + weight[j] <= x) 
        {
            ++i;
            --j;
        } 
        else 
        {
            --j;
        }
        ++gondolas;
    }

    cout << gondolas << endl;
    return 0;
}
