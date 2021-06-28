#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <math.h>
#include <string>
#include <tuple>

using namespace std;



int main()
{
	int n;
	scanf("%d", &n);


	int age;
	char str[50 + 1];
	vector<tuple<int, string, int>> vec;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d %s", &age, str);
		vec.push_back(make_tuple(age, string(str), i));
	}


	sort(vec.begin(), vec.end(), [](const tuple<int, string, int>& a, const tuple<int, string, int>& b) -> bool
		{
			if (std::get<0>(a) == std::get<0>(b))
			{
				return std::get<2>(a) < std::get<2>(b);
			}
			return std::get<0>(a) < std::get<0>(b);
		});

	for (int i = 0; i < n; ++i)
	{
		if (i != 0 && vec[i] == vec[i - 1])
			continue;

		printf("%d %s\n", std::get<0>(vec[i]), std::get<1>(vec[i]).c_str());
	}
}

