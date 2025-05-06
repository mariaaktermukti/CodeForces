#include <bits/stdc++.h>
using namespace std;

int main() 
{
    int testCases;
    cin >> testCases;
    
    while (testCases--) 
    {
        int numElements, numQueries;
        cin >> numElements >> numQueries;
        vector<int> sequence(numElements + 1);
        
        for (int idx = 1; idx <= numElements; idx++) 
        {
            cin >> sequence[idx];
        }
        
        vector<int> tallyX(numElements + 1, 0), tallyY(numElements + 1, 0), tallyZ(numElements + 1, 0);
        
        for (int idx = 1; idx <= numElements; idx++) 
        {
            tallyX[idx] = tallyX[idx - 1] + (sequence[idx] == 1);
            tallyY[idx] = tallyY[idx - 1] + (sequence[idx] == 2);
            tallyZ[idx] = tallyZ[idx - 1] + (sequence[idx] == 3);
        }
        
        while (numQueries--) 
        {
            int startIdx, endIdx;
            cin >> startIdx >> endIdx;
            int span = endIdx - startIdx + 1;
            
            if (span % 2 != 0) 
            {
                cout << "No" << endl;
                continue;
            }
            
            int halfSpan = span / 2;
            int countX = tallyX[endIdx] - tallyX[startIdx - 1];
            int countY = tallyY[endIdx] - tallyY[startIdx - 1];
            int countZ = tallyZ[endIdx] - tallyZ[startIdx - 1];
            int qualifiedCategories = 0;
            
            if (countX >= halfSpan) qualifiedCategories++;
            if (countY >= halfSpan) qualifiedCategories++;
            if (countZ >= halfSpan) qualifiedCategories++;
            
            if (countX <= halfSpan && countY <= halfSpan && countZ <= halfSpan && qualifiedCategories >= 1) 
            {
                cout << "Yes" << endl;
            } 
            else 
            {
                cout << "No" << endl;
            }
        }
    }
    
    return 0;
}