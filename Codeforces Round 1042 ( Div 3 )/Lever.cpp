#include <bits/stdc++.h>
using namespace std;

long long sumPositiveDiffRecursive(const vector<int>& arr, const vector<int>& target, int position) 
{
    int length = arr.size();
    if (position == length) return 0;                       
    long long curDiff = max(0, arr[position] - target[position]); 
    return curDiff + sumPositiveDiffRecursive(arr, target, position + 1);
}

int main() 
{
    int t;
    if (!(cin >> t)) return 0;
    while (t--) 
    {
        int len; 
        cin >> len;
        vector<int> arr(len), target(len);
        for (int i = 0; i < len; ++i) 
        {
            cin >> arr[i];
        }
        for (int i = 0; i < len; ++i) 
        {
            cin >> target[i];
        }
        long long totalDecrease = sumPositiveDiffRecursive(arr, target, 0);
        cout << totalDecrease + 1 << endl; 
    }
    return 0;
}
