#include <iostream>

unsigned int fibonacci_rcsv(unsigned int n) {

    std::cout << n << "\n";
    
    if (n == 0) return 0; // 제 0항은 0을 반환한다.
    else if (n == 1) return 1; // 제 1항은 1을 반환한다.
    else return fibonacci_rcsv(n - 2) + fibonacci_rcsv(n - 1);

}

long long fiboBottomUp(int n) 
{
    if (n == 1 || n ==  2) return 1;
    long long bottomUp[100000];
    for (int i = 0; i < 100000; ++i)
        bottomUp[i] = 0;
    bottomUp[1] = 1;
    bottomUp[2] = 1;
    for (int i = 3; i <= n; i++) {
        bottomUp[i] = bottomUp[i - 1] + bottomUp[i - 2];
    }
    return bottomUp[n];
}

int main()
{
    long long a = fiboBottomUp(100);
}
