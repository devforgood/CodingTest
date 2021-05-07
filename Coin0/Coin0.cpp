
#include <iostream>
#include <string>

using namespace std;

int main()
{
    int N, K;
    int arr[10] = { 0, };
    cin >> N >> K;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int answer = 0;

    for (int i = N - 1; i >= 0; --i)
    {
        if (K >= arr[i])
        {
            int cnt = K / arr[i];
            K -= arr[i] * cnt;
            answer += cnt;
        }
        if (K == 0)
            break;
    }


    cout << answer;

}
