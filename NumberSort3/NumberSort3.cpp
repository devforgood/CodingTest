#include <iostream>
#include <vector>
#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>

using namespace std;



int main()
{
	int n, v;
	int arr[10000 + 1];
	scanf("%d", &n);
	std::fill_n(arr, 10000 + 1, 0);

	int length = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v);
		++arr[v];
		if (length < v)
			length = v;
	}

	for (int i = 0; i <= length; ++i)
	{
		for (int j = 0; j < arr[i]; ++j)
			printf("%d ", i);
	}
	printf("\n");

}

