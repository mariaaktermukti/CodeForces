#include <iostream>
using namespace std;

void printDigits(int N) {
    if (N < 10) {
        cout << N << " ";
        return;
    }

    printDigits(N / 10);
    cout << N % 10 << " ";
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int N;
        cin >> N;
        
        printDigits(N); 
        cout << "\n";   
    }
    
    return 0;
}
