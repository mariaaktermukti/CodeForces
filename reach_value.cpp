#include <iostream>
using namespace std;

bool canReach(long long current, long long N) {
    if (current == N) return true; 
    if (current > N) return false;

    return canReach(current * 10, N) || canReach(current * 20, N);
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        long long N;
        cin >> N;

        if (canReach(1, N)) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}
