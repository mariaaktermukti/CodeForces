#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int testCount;
    cin >> testCount;
    while (testCount--) 
    {
        int length, targetSum;
        cin >> length >> targetSum;
        vector<int> values(length);
        int countByValue[3] = {0, 0, 0};
        int directSum = 0;
        for (int i = 0; i < length; i++) 
        {
            cin >> values[i];
            countByValue[values[i]]++;
            directSum += values[i];
        }

        if (targetSum < directSum) 
        {
            for (int v : values) cout << v << ' ';
            cout << '\n';
            continue;
        }
        if (targetSum == directSum) 
        {
            cout << -1 << '\n';
            continue;
        }

        int extraNeeded = targetSum - directSum;
        vector<int> permutation = {0, 1, 2};
        bool blocked = false;

        do {
            vector<int> arranged;
            for (int v : permutation) 
            {
                for (int k = 0; k < countByValue[v]; k++) 
                {
                    arranged.push_back(v);
                }
            }

            vector<int> coinValues;
            bool seenSum[5] = {false};
            for (int i = 0; i + 1 < length; i++) 
            {
                int cycleValue = arranged[i] + arranged[i+1];
                if (cycleValue > 0 && !seenSum[cycleValue]) 
                {
                    seenSum[cycleValue] = true;
                    coinValues.push_back(cycleValue);
                }
            }
            vector<bool> reachable(extraNeeded + 1, false);
            reachable[0] = true;
            for (int sum = 1; sum <= extraNeeded; sum++) 
            {
                for (int coin : coinValues) 
                {
                    if (coin <= sum && reachable[sum - coin]) 
                    {
                        reachable[sum] = true;
                        break;
                    }
                }
            }

            if (!reachable[extraNeeded]) 
            {
                for (int v : arranged) cout << v << ' ';
                cout << '\n';
                blocked = true;
                break;
            }
        } while (next_permutation(permutation.begin(), permutation.end()));

        if (!blocked) 
        {
            cout << -1 << '\n';
        }
    }
    return 0;
}
