#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

char s1[1002];
char s2[1002];
int dp[1001][1001];

void print(int i, int j) {
    if (dp[i][j] == 0)return;
    if (s1[i - 1] == s2[j - 1]) {
        print(i - 1, j - 1);
        cout << s1[i - 1];
    }
    else
    {
        if (dp[i - 1][j] > dp[i][j - 1])
            print(i - 1, j);
        else
            print(i, j - 1);
    }
}

int main() {
    cin >> s1 >> s2;

    int i, j;
    for (i = 0; s1[i]; i++)
        for (j = 0; s2[j]; j++)
        {
            if (s1[i] == s2[j])
                dp[i + 1][j + 1] = dp[i][j] + 1;
            else
            {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }

    cout << dp[i][j] << "\n";
    print(i, j);
    return 0;
}