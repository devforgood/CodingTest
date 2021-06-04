#include <algorithm>
#include <string>
#include <iostream>

int main()
{
    int total_number = 0;
    int even_number = 0;
    std::string s = "12345";
    std::string num;
    int r = 3;
    std::sort(s.begin(), s.end());
    do {
        num = s.substr(0, r);
        std::cout << num << '\n';
        if (atoi(num.c_str()) % 2 == 0)
            ++even_number;
        ++total_number;

        std::reverse(s.begin() + r, s.end());

    } while (std::next_permutation(s.begin(), s.end()));

    
}
