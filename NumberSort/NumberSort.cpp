#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	int n, v;
	vector<int> vec;
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> v;
		vec.push_back(v);
	}

	sort(vec.begin(), vec.end());

	for (int i = 0; i < n; ++i)
		cout << vec[i] << '\n';

}

