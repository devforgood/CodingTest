#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(int n) 
{
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if ((n % i) == 0) {
            return false;
        }
    }

    return true;
}

int main()
{
	int t, n;

	cin >> t;
	while (t--)
	{
		cin >> n;

		for (int i = n/2; i >0; --i)
		{
			if (isPrime(i) && isPrime(n - i))
			{
				cout << i << " " << n - i << "\n";
				break;
			}
		}
	}

}

