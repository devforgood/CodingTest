#include <iostream>

using namespace std;

bool PrimeArray[1000001];

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
	int n, m;
	cin >> m >> n;
	Eratos(n+1);

	for (int i = m; i <= n; ++i)
	{
		if (PrimeArray[i])
		{
			cout << i << "\n";
		}
	}
}

