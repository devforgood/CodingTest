#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <math.h>
#include <set>


using namespace std;



int main()
{
	int n;
	scanf("%d", &n);


	int x;
	vector<pair<int, int>> vec;

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &x);
		vec.push_back(make_pair(x, i));
	}

	sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool
		{
			return a.first < b.first;
		});

	int last_value = 0;
	int index = 0;
	for (int i = 0; i < n; ++i)
	{
		if (i != 0 && vec[i].first != last_value)
			++index;
		last_value = vec[i].first;
		vec[i].first = index;
	}

	sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool
		{
			return a.second < b.second;
		});

	for (int i = 0; i < n; ++i)
	{
		printf("%d\n", vec[i].first);
	}
}

