
bool PrimeArray[1000];

void Eratos(int n)
{
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
