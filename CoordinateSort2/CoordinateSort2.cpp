#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <math.h>


using namespace std;



int main()
{
	int n;
	scanf("%d", &n);


	pair<int, int> point;
	vector<pair<int, int>> vec;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %d", &point.first, &point.second);
		vec.push_back(point);
	}


	sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool
		{
			if (a.second == b.second)
			{
				return a.first < b.first;
			}
			return a.second < b.second;
		});

	for (int i = 0; i < n; ++i)
	{
		printf("%d %d\n", vec[i].first, vec[i].second);
	}
}

