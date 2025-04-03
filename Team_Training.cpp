#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    while(t--) {
        int n, x;
        cin >> n >> x;
        vector<int> skills(n);
        for (int i = 0; i < n; i++){
            cin >> skills[i];
        }

        sort(skills.begin(), skills.end(), greater<int>());
        
        int teams = 0;
        int teamSize = 0;
        for (int i = 0; i < n; i++){
            teamSize++; 
            if (skills[i] * teamSize >= x) {
                teams++;
                teamSize = 0;
            }
        }
        cout << teams << "\n";
    }
    
    return 0;
}
