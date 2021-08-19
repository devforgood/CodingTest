
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long long a;
	long long min_value = 1000000;
	long long max_value = 0;
	for(int i=0;i<n;++i)
	{
		cin >> a;
		if (min_value > a)
			min_value = a;
		if (max_value < a)
			max_value = a;
	}

	cout << min_value*max_value;
}
