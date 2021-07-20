#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int arr[1000] = { 0, };
    int dp[1000] = { 0, };
    int dp2[1000] = { 0, };

    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    // 가장 긴 증가하는 부분 수열과 역으로 가장 긴 증가하는 부분 수열 두가지를 구해서
    // 두개의 수열의 조합중 가장 큰수를 고른다.
    for (int i = 0; i < n; ++i)
    {
        dp[i] = 1;
        dp2[n - i-1] = 1;
        for (int j = 0; j < n; ++j)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;

            if (arr[n - i-1] > arr[n - j-1] && dp2[n - i-1] < dp2[n - j-1] + 1)
                dp2[n - i-1] = dp2[n - j-1] + 1;
        }


    }

    int max_value = 0;
    for (int i = 0; i < n; ++i)
    {
        max_value = max(max_value, dp[i] + dp2[i]);
    }



    printf("%d\n", max_value -1);

}
