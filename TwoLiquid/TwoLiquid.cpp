#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int arr[100000] = { 0, };
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];


	sort(arr, arr + n);

	int min = 2000'000'000;
	int a, b, c;
	int start = 0;
	int end = n - 1;

	while (start < end)
	{
		c = arr[start] + arr[end];


		if (abs(c) < min)
		{
			min = abs(c);
			a = arr[start];
			b = arr[end];

			if (min == 0)
				break;
		}

		if (c < 0)
			++start;
		else
			--end;

	}

	cout << a << " " << b << "\n";

}