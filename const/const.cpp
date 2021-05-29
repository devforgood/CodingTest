#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    string num;
    for (int i = a.length() - 1; i >= 0; --i)
        num += a[i];


    string num2;
    for (int i = b.length() - 1; i >= 0; --i)
        num2 += b[i];

    if (atoi(num.c_str()) > atoi(num2.c_str()))
        cout << num;
    else
        cout << num2;


}