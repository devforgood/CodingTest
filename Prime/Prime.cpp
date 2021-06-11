// PrimeSearch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

bool PrimeArray[10002];

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
	Eratos(10000);
	int n, m;
	cin >> m >> n;
	int sum = 0;
	int min = 10001;
	for (int i = m; i <= n; ++i)
	{
		if (PrimeArray[i])
		{
			sum += i;
			if (min > i)
				min = i;
		}
	}
	if (sum == 0)
		cout << -1;
	else
		cout << sum << endl << min;
}

