#include <iostream>
#include <string>

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;

    for (int i = 0; i < t; i++) 
    {
        std::string s;
        std::cin >> s; 

        std::string t_str = "";   
        std::string other_str = "";

        for (char c : s) 
        {
            if (c == 'T') 
            {
                t_str += c;    
            } 
            else 
            {
                other_str += c;
            }
        }
        std::cout << t_str + other_str << '\n';
    }

    return 0;
}