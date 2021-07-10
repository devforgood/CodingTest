#include <iostream>

using namespace std;

long long arr[1000001] = { 0, };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);


    arr[1] = 1;
    arr[2] = 1;
    arr[3] = 1;

    for (int i = 4; i <= 100; i++) {
        arr[i] = arr[i - 3] + arr[i - 2];
    }
    int n, v;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> v;
        cout << arr[v] << "\n";
    }


}
