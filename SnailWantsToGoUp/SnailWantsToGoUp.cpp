#include <iostream>
#include <string>

using namespace std;

int main()
{
	int a, b, v;
	cin >> a >> b >> v;

	int days = (v-a) / (a-b) +1;
	days += (v - a) % (a - b) > 0 ? 1 : 0;
	

	cout << days;
}