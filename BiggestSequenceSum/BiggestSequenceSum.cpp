#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

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
        dp[i] = 1;
        for (int j = 0; j < n; ++j)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
        }

        if (max_value < dp[i])
            max_value = dp[i];
    }


    printf("%d\n", max_value);

}
