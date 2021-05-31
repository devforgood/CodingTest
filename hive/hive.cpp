#include <iostream>
#include <string>

using namespace std;

int main()
{
	long long n;
	cin >> n;

	long long dist = 1;
	if (n > 1)
	{
		for (long long i = dist*6+1; i <= 1000000000;)
		{
			if (i >= n)
				break;
			++dist;
			i += dist * 6;
		}
		++dist;
	}

	cout << dist;
}