#include <iostream>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int cnt;
        cin >> cnt;
        string str;
        cin >> str;

        for (int j = 0; j < str.length(); ++j)
        {
            for (int k = 0; k < cnt; ++k)
            {
                cout << str[j];
            }
        }

        if(i+1 != n)
            cout << "\n";
    }


}