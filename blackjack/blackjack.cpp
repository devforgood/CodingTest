// blackjack.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int main()
{
    int m, n;
    int arr[100] = { 0, };
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    int max = 0;
    for (int i = 0; i < n - 2; ++i)
    {
        for (int j = i + 1; j < n - 1; ++j)
        {
            for (int k = j + 1; k < n; ++k)
            {
                if (arr[i] + arr[j] + arr[k] <= m && arr[i] + arr[j] + arr[k] > max)
                {
                    max = arr[i] + arr[j] + arr[k];
                }
            }
        }
    }

    cout << max;

}
