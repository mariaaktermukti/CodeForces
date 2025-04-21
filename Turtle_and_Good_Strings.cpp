#include <iostream>
#include <string>

int main() {
    int t; 
    std::cin >> t;
    while (t--) {
        int n; 
        std::string s;
        std::cin >> n >> s;

        if (s.front() != s.back()) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
