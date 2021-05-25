#include <iostream>
#include <string>

int main()
{
    int A, B;
    std::cin >> A >> B;
    auto str = std::to_string(B);

    for (int i = str.length()-1; i >= 0; --i)
        std::cout << A * (str[i] - '0') << "\n";

    std::cout << A * B << "\n";
    


}