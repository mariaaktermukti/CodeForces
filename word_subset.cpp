#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) 
    {
        vector<int> requiredFreq(26, 0);
        
        for (const string& word : words2) 
        {
            vector<int> currentFreq(26, 0);
            for (char c : word) 
            {
                currentFreq[c - 'a']++;
            }
            for (int i = 0; i < 26; i++) 
            {
                requiredFreq[i] = max(requiredFreq[i], currentFreq[i]);
            }
        }
        
        vector<string> result;
        for (const string& word : words1) 
        {
            vector<int> wordFreq(26, 0);
            for (char c : word) 
            {
                wordFreq[c - 'a']++;
            }
            
            bool isUniversal = true;
            for (int i = 0; i < 26; i++) 
            {
                if (wordFreq[i] < requiredFreq[i]) 
                {
                    isUniversal = false;
                    break;
                }
            }
            
            if (isUniversal) 
            {
                result.push_back(word);
            }
        }
        
        return result;
    }
};

int main() {
    vector<string> words1 = {"amazon","apple","facebook","google","leetcode"};
    vector<string> words2 = {"e","o"};
    Solution solution;
    vector<string> result = solution.wordSubsets(words1, words2);
    
    cout << "Universal words are: ";
    for (const string& word : result) 
    {
        cout << word << " ";
    }
    cout << endl;
    
    return 0;
}
