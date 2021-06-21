#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;

	vector<pair<int, int>> vec;

	for (int i = 0; i < n; ++i)
	{
		pair<int, int> p;
		cin >> p.first >> p.second;
		vec.push_back(p);
	}

	for (int i = 0; i < n; ++i)
	{
		int rank = 1;
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;

			if (vec[i].first < vec[j].first && vec[i].second < vec[j].second)
				++rank;
		}
		cout << rank << " ";

	}



}

