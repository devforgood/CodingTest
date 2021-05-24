#include <algorithm>
#include <iostream>
#include <cstring>
#include <string>

using namespace std;
int main()
{
	string a, b, answer;
	cin >> a;
	cin >> b;


	if (a.length() > b.length())
		b = std::string(a.length() - b.length(), '0').append(b);
	else
		a = std::string(b.length() - a.length(), '0').append(a);
	
	int carry = 0;
	for (int i = 1; i <= a.length(); ++i)
	{
		int sum = a[a.length() - i] - '0' + b[b.length() - i] - '0' + carry;
		carry = sum / 10;
		answer = (char)(sum % 10 + '0') + answer;
	}

	if (carry != 0)
		answer = (char)(carry + '0') + answer;
	
	cout << answer;

}
