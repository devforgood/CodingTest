#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>

using namespace std;

bool PrimeArray[4000001];

void Eratos(int n)
{
    PrimeArray[0] = false;
    PrimeArray[1] = false;

    for (int i = 2; i < n + 1; ++i)
        PrimeArray[i] = true;


    for (int i = 2; i * i <= n; ++i)
    {
        if (PrimeArray[i])
        {
            for (int j = i * i; j <= n; j += i)
                PrimeArray[j] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    Eratos(n);

    vector<int> arr;
    for (int i = 0; i <= n; ++i)
        if (PrimeArray[i])
            arr.push_back(i);


    int start = 0;
    int end = 0;
    int sum = 0;
    int count = 0;

    while (start <= end)
    {
        if (sum >= n)
        {
            if (sum == n)
            {
                ++count;
            }
            sum -= arr[start++];
        }
        else if (end >= arr.size())
            break;
        else
        {
            sum += arr[end++];
        }
    }
    cout << count << "\n";
}
