#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAX = 360000;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	string a, b;
	int n;
	cin >> n;
	for (int i = 0; i < MAX; ++i)
	{
		a += '0';
		b += '0';
	}
	for (int i = 0; i < n; ++i)
	{
		int c;
		cin >> c;
		a[c] = '1';
	}
	for (int i = 0; i < n; ++i)
	{
		int c;
		cin >> c;
		b[c] = '1';
	}



	string T, P;
	T = b + b;
	P = a;

	int m = P.length();
	vector<int> fail(m);
	for (int i = 1, j = 0; i < m; ++i)
	{
		while (j > 0 && P[i] != P[j])
			j = fail[j - 1];

		if (P[i] == P[j])
			fail[i] = ++j;
	}

	bool isPossible = false;
	for (int i = 0, j = 0; i < T.length(); ++i)
	{
		while (j > 0 && T[i] != P[j])
			j = fail[j - 1];

		if (T[i] == P[j])
		{
			++j;

			if (j == m)
			{
				isPossible = true;
			}
		}
	}


	if (isPossible == false)
		cout << "impossible";
	else
		cout << "possible";
}