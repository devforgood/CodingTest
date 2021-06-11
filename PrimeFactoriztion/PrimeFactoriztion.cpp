#include <iostream>
#include <vector>\

using namespace std;

int main()
{
	int n, t;
	cin >> n;
	t = n;
	vector<int> factor;

	for (int i = 2; i * i <= t; ++i)
	{
		while (n % i == 0)
		{
			n /= i;
			factor.push_back(i);
		}
	}
	if (t != 1)
	{
		if (n != 1)
			factor.push_back(n);
		for (int i : factor)
			cout << i << endl;
	}

}