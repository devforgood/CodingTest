#include <iostream>

using namespace std;

int arr[1000001] = { 0, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

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
