
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;



	int answer = 0;

	int last_index = 0;
	string num;
	bool is_sub = false;
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == '+' || str[i] == '-')
		{
			num = str.substr(last_index, i- last_index);
			last_index = i + 1;

			if(is_sub)
				answer -= atoi(num.c_str());
			else
				answer += atoi(num.c_str());


			if (str[i] == '-')
				is_sub = true;
		}
	}

	num = str.substr(last_index, str.length() - last_index);
	if (is_sub)
		answer -= atoi(num.c_str());
	else
		answer += atoi(num.c_str());



	cout << answer;

}
