// Knapsack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

using namespace std;
int N, K, item[102][2], dp[102][100'003];

int main()
{
    ios::sync_with_stdio(0); 
    cin.tie(0);

    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        cin >> item[i][0] >> item[i][1];
    }

    for (int i = 1; i <= N; i++)
    {
        int weight = item[i][0], val = item[i][1];
        for (int j = 0; j <= K; j++)
        {
            if (j < weight)
                dp[i][j] = dp[i - 1][j];
            else
            {
                // 적은 무게로 큰 가치
                // 물건을 담지 않는 경우 와 물건을 담는 경우를 비교하여 가치가 큰것으로 결정
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight] + val);
            }
        }
    }

    cout << dp[N][K];
}
