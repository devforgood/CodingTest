#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    int arr[1000] = { 0, };
    int dp[1000] = { 0, };
    int trace[1000] = { 0, };

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }

    int max_value = 0;
    int max_index = 0;
    for (int i = 0; i < n; ++i)
    {
        // 0 ~ i 이전까지만 i와 비교하여 작은 경우 카운드 및 DP 에 기록
        dp[i] = 1; // 자기 자신 1로 세팅
        trace[i] = -1;

        for (int j = 0; j < i; ++j)
        {
            if (arr[i] > arr[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
                trace[i] = j;
            }
        }

        if (max_value < dp[i])
        {
            max_value = dp[i];
            max_index = i;
        }
    }


    cout << max_value << "\n";

    
    vector<int> v;
    n = max_index;
    for (; n != -1; n = trace[n])
        v.push_back(arr[n]);

    for (int i = v.size()-1; i >= 0; --i)
        cout << v[i] << " ";

}
