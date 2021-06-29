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

void backtracking(int n, int m, vector<int> permutation, int cur)
{
	permutation.push_back(cur);

	if (permutation.size() == m)
	{
		for (int i = 0; i < permutation.size(); ++i)
			printf("%d ", permutation[i]);
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		if (std::find(permutation.begin(), permutation.end(), i) != permutation.end())
			continue;

		backtracking(n, m, permutation, i);
	}

}

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	vector<int> permutation;
	for(int i=1;i<=n;++i)
		backtracking(n, m, permutation, i);
}

