#define _CRT_SECURE_NO_WARNINGS

#include <iostream>

using namespace std;

int main()
{
    int n;
    int arr[1000] = { 0, };
    int dp[1000] = { 0, };

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int max_value = 0;
    for (int i = 0; i < n; ++i)
    {
        // 0 ~ i 이전까지만 i와 비교하여 작은 경우 카운드 및 DP 에 기록
        dp[i] = 1; // 자기 자신 1로 세팅
        for (int j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }

        if (max_value < dp[i])
            max_value = dp[i];
    }


    printf("%d\n", max_value);

}
