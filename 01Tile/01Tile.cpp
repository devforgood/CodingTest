#include <iostream>

using namespace std;

int arr[1000001] = { 0, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    // n의 값에 대응되는 결과를 1부터 차례대로 나열
    // 수열에 규칙을 찾아 점화식을 만든다. (피보나치 수열과 동일)

    int n;
    cin >> n;
    arr[1] = 1;
    arr[2] = 2;
    for (int i = 3; i <= n; i++) {
        arr[i] = arr[i - 2] + arr[i - 1];
        arr[i] %= 15746;
    }
   
    cout << arr[n];


}
