#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int arr[1000] = { 0, };
    int dp[1000] = { 0, };

    scanf("%d", &n);

    vector<pair<int, int>> vec;

    int a, b;
    for (int i = 0; i < n; ++i)
    {
        scanf("%d %d", &a, &b);

        vec.push_back(make_pair(a, b));
    }

    //1. 왼쪽 전봇대를 기준으로 정렬을 시켜준다.
    sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) -> bool
        {
            return a.first < b.first;
        });

    for (int i = 0; i < n; ++i)
        arr[i] = vec[i].second;

    //  2. 오른쪽 전봇대에서 "가장 긴 증가하는 부분 수열"을 구해준다.
    int max_value = 0;
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        for (int j = 0; j < n; ++j)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }

        if (max_value < dp[i])
            max_value = dp[i];
    }

    //3. 2번과정에서 구한 "가장 긴 증가하는 부분 수열"의 크기를 N에서 빼준다.
    printf("%d\n", n-max_value);

}
