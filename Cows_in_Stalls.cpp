#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool canPlaceCows(const vector<int>& stalls, int k, int dist) 
{
    int count = 1; 
    int last_position = stalls[0];

    for (int i = 1; i < stalls.size(); ++i) 
    {
        if (stalls[i] - last_position >= dist) 
        {
            count++;
            last_position = stalls[i];
        }
        if (count == k) return true;
    }
    return false;
}

int main() 
{
    int n, k;
    cin >> n >> k;
    vector<int> stalls(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> stalls[i];
    }

    sort(stalls.begin(), stalls.end()); 

    int low = 1; 
    int high = stalls[n - 1] - stalls[0];
    int answer = 0;

    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (canPlaceCows(stalls, k, mid)) 
        {
            answer = mid;
            low = mid + 1; 
        } 
        else 
        {
            high = mid - 1; 
        }
    }

    cout << answer << endl;
    return 0;
}
