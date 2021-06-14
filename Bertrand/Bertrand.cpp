#include <iostream>

using namespace std;

bool PrimeArray[123456 * 2 +1];

void Eratos(int n)
{
	PrimeArray[0] = false;
	PrimeArray[1] = false;

	for (int i = 2; i < n + 1; ++i)
		PrimeArray[i] = true;


	for (int i = 2; i * i <= n; ++i)
	{
		if (PrimeArray[i])
		{
			for (int j = i * i; j <= n; j += i)
				PrimeArray[j] = false;
		}
	}
}

int main()
{
	Eratos(123456 * 2);

	int n;
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;

		int cnt = 0;
		for (int i = n+1; i <= n * 2; ++i)
		{
			if (PrimeArray[i])
			{
				++cnt;
			}
		}
		cout << cnt << "\n";
	}

}

