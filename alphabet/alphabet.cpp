#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str;
    cin >> str;

    for (char i = 'a'; i <= 'z'; ++i)
    {
        int j = 0;
        for (; j < str.length(); ++j)
        {
            if (str[j] == i)
            {
                cout << j;
                break;
            }
        }

        if (j == str.length())
        {
            cout << -1;
        }

        if (i != 'z')
            cout << " ";
    }
}