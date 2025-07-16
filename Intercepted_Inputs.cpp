#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main() 
{
    int t;
    cin >> t; 

    while (t--) 
    {
        int k;
        cin >> k;

        vector<int> arr(k);
        unordered_set<int> nums; 

        for (int i = 0; i < k; ++i) 
        {
            cin >> arr[i];
            nums.insert(arr[i]);
        }

        int product = k - 2; 

        bool found = false;
        for (int n = 1; n * n <= product; ++n) 
        {
            if (product % n == 0) 
            {
                int m = product / n;
                if (nums.count(n) && nums.count(m)) 
                {
                    cout << n << " " << m << endl;
                    found = true;
                    break;
                }
            }
        }

        if (!found) 
        {
            cout << "1 " << product << endl;
        }
    }

    return 0;
}
