#include <iostream>

int gcd(int a, int b)
{
    int tmp;
    while (b != 0)
    {
        tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

int lcm(int a, int b)
{
    return (a * b) / gcd(a, b);
}


int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << gcd(a, b) << "\n";
    std::cout << lcm(a, b) << "\n";
}

