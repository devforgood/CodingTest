// PrimeSearch.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;

bool PrimeArray[1001];

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

int main()
{
	Eratos(1000);
	int n;
	cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		int number;
		cin >> number;
		if (PrimeArray[number])
			++cnt;
	}
	cout << cnt;
}

