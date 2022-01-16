#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;




int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int m;
	string P;
	cin >> m >> P;

	vector<int> fail(m);
	fail[0] = 0;

	for (int i = 1, j = 0; i < m; ++i)
	{
		while (j > 0 && P[i] != P[j])
			j = fail[j - 1];

		if (P[i] == P[j])
			fail[i] = ++j;
	}

	cout << m - fail[m - 1] << "\n";



}