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

	string T, P;
	getline(cin, T);
	getline(cin, P);

	int m = P.length();
	vector<int> fail(m);
	fail[0] = 0;

	for (int i = 1, j = 0; i < m; ++i)
	{
		while (j > 0 && P[i] != P[j])
			j = fail[j - 1];

		if (P[i] == P[j])
			fail[i] = ++j;
	}

	vector<int> answer;
	int n = T.length();
	for (int i = 0, j = 0; i < n; ++i)
	{
		while (j > 0 && T[i] != P[j])
			j = fail[j - 1];

		if (T[i] == P[j])
		{
			if (j == m - 1)
			{
				answer.push_back(i - m + 1 + 1);
				j = fail[j];
			}
			else
				++j;
		}
	}

	cout << answer.size() << "\n";
	for (int i = 0; i < answer.size(); ++i)
		cout << answer[i] << " ";


}