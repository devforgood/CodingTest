#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <math.h>
#include <string>


using namespace std;



int main()
{
	int n;
	scanf("%d", &n);


	char str[50+1];
	vector<string> vec;
	for (int i = 0; i < n; ++i)
	{
		scanf("%s", str);
		vec.push_back(str);
	}


	sort(vec.begin(), vec.end(), [](const string& a, const string& b) -> bool
		{
			if (a.length() == b.length())
			{
				return a < b;
			}
			return a.length() < b.length();
		});

	for (int i = 0; i < n; ++i)
	{
		if (i != 0 && vec[i] == vec[i - 1])
			continue;

		printf("%s\n", vec[i].c_str());
	}
}

