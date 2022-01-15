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


	while (true)
	{
		string P;
		getline(cin, P);
		if (P == ".")
			break;

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

		// 문자열에서 A글자의 패턴을 만들수 있음과 문자열의 앞쪽(N-A)글자와 뒤쪽(N-A)글자가 같음은 동치
		if (m % (m - fail[m - 1]))
			cout << 1 << "\n";
		else
			cout << m / (m - fail[m - 1]) << "\n";

	}



}