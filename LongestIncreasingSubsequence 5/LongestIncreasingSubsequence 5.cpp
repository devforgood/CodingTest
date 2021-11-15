#include <iostream>
#include <vector>

using namespace std;

int arr[1000001] = { 0, };
int trace[1000001] = { 0, };

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i)
    {
        cin >> arr[i];
    }

    int index = 0;
    vector<int> v;
    v.push_back(arr[1]);

    for (int i = 2; i <= n; ++i)
    {
        if (v[index] < arr[i])
        {
            v.push_back(arr[i]);
            ++index;
            trace[i] = index;
        }
        else
        {
            int index2 = lower_bound(v.begin(), v.end(), arr[i]) - v.begin();
            v[index2] = arr[i];
            trace[i] = index2;
        }
    }

    cout << index + 1 << "\n";


    vector<int> answer;
    for (int i = n; i >= 1 && index >= 0; i--) 
    {
        if (trace[i] == index) {
            answer.push_back(arr[i]);
            index--;
        }
    }
    for (int i = answer.size() - 1; i >= 0; i--) 
    {
        cout << answer[i] << " ";
    }
}
