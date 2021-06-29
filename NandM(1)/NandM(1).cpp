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

void backtracking(int n, int m, vector<int> combination, int cur)
{
	combination.push_back(cur);

	if (combination.size() == m)
	{
		for (int i = 0; i < combination.size(); ++i)
			printf("%d ", combination[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (std::find(combination.begin(), combination.end(), i) != combination.end())
			continue;

		backtracking(n, m, combination, i);
	}

}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> combination;
	for(int i=1;i<=n;++i)
		backtracking(n, m, combination, i);
}

