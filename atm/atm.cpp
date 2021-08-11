
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	int arr[1000] = { 0, };
	cin >> n;



	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}


	sort(arr, arr+n);

	int answer = arr[0];
	for (int i = 1; i < n; ++i)
	{
		arr[i] += arr[i - 1];
		answer += arr[i];
	}


	cout << answer;

}
