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
	int n, v;
	scanf("%d", &n);


	map<int, int> counted;
	vector<int> nums;
	int max_count = 0;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &v);
		nums.push_back(v);
		++counted[v];
		if (max_count < counted[v])
		{
			max_count = counted[v];
		}
	}

	vector<int> nums2;
	for (auto i : counted)
	{
		if (i.second == max_count)
			nums2.push_back(i.first);
	}


	sort(nums.begin(), nums.end());
	int max_value = nums2[0];
	if (nums2.size() > 1)
	{
		sort(nums2.begin(), nums2.end());
		max_value = nums2[1];
	}

	//산술평균 : N개의 수들의 합을 N으로 나눈 값
	printf("%d\n", (int)(floor((double)std::accumulate(nums.begin(), nums.end(), 0) / n + 0.5)));

	//중앙값 : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값
	printf("%d\n", nums[n / 2]);

	//최빈값 : N개의 수들 중 가장 많이 나타나는 값
	printf("%d\n", max_value);

	//범위 : N개의 수들 중 최댓값과 최솟값의 차이
	printf("%d\n", *std::max_element(nums.begin(), nums.end()) - *std::min_element(nums.begin(), nums.end()));

}

