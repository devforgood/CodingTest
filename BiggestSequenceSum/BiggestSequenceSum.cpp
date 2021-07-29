#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[100000] = { 0, };
int dp[100000] = { 0, };

int main()
{
    int n;
  
    scanf("%d", &n);

    for (int i = 0; i < n; ++i)
    {
        scanf("%d", &arr[i]);
    }

    int max_value = -9e8;
    for (int i = 0; i < n; ++i)
    {
        dp[i] = arr[i];

        if (i > 0)
        {
            dp[i] = max({ dp[i],dp[i - 1] + dp[i] });
        }
  
        if (max_value < dp[i])
            max_value = dp[i];
    }


    printf("%d\n", max_value);

}
