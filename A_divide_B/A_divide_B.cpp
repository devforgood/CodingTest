#include <iostream>
int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << a + b << "\n";
    std::cout << a - b << "\n";
    std::cout << a * b << "\n";

    std::cout.precision(10);
    std::cout << a / b << "\n";
    std::cout << a % b << "\n";
}