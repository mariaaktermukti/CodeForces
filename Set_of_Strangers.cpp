#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; 
    cin >> t;
    while(t--){
        int n, m; 
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cin >> grid[i][j];
            }
        }
        
        unordered_map<int, bool> conflict;
        unordered_map<int, bool> exists;
 
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                int col = grid[i][j];
                exists[col] = true;
                if(j + 1 < m){
                    if(grid[i][j+1] == col){
                        conflict[col] = true;
                    }
                }
                if(i + 1 < n){
                    if(grid[i+1][j] == col){
                        conflict[col] = true;
                    }
                }
            }
        }
        int base = 0;
        int best = 0; 
        for(auto &p : exists){
            int col = p.first;
            int cost = (conflict.count(col) && conflict[col]) ? 2 : 1;
            base += cost;
            best = max(best, cost);
        }
        int ans = base - best;
        cout << ans << "\n";
    }
    return 0;
}
