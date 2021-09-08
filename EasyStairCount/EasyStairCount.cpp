#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
using namespace std;

#define MOD 1000000000

int main() {

    int n, i, j;
    int dp[101][11] = { 0, };
    int sum = 0;

    scanf("%d", &n);

    // 1자리 1로 초기화
    for (i = 0; i <= 9; i++)
        dp[1][i] = 1;

    ///////////////////////////////////////////////////////////////
    // 아래 값은 1~9까지 반복해서 n이 3일때 조합된 것을 보여준다.
    // 
    //             1
    //     10            12
    //  X     101    121    123
    //
    //             2
    //     21             23
    // 210    212     232    234
    // 
    // ...
    // 
    //             9
    //      98             X   
    //  987    989      X     X
    //
    ///////////////////////////////////////////////////////////////

    for (i = 2; i <= n; i++) {
        dp[i][0] = dp[i - 1][1];
        dp[i][10] = 0;
        for (j = 0; j <= 9; j++) {
            dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % MOD;
        }
    }

    for (i = 1; i <= 9; i++) sum = (sum + dp[n][i]) % MOD;
    printf("%d\n", sum);

    return 0;
}