// TwoNumberSum.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    int arr[100000] = { 0, };
    cin >>n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    int x;
    cin >> x;

    sort(arr, arr + n);

    int answer = 0;
    for (int i = 0; i < n-1; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {

            if (arr[i] + arr[j] == x)
                ++answer;
            else if (arr[i] + arr[j] > x)
                break;
        }
    }

    cout << answer;
}
/*

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,x;
vector<int> nums;
int cnt = 0;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N;
    int tmp;
    for(int i = 0 ; i < N ; i++){
        cin >> tmp;
        nums.push_back(tmp);
    }
    cin >> x;
    sort(nums.begin(),nums.end());
    int start = 0;
    int end = N - 1;
    while(1){
        if(start >= end) break;
        tmp = nums[start] + nums[end];
        if(tmp == x){
            start++;
            end--;
            cnt++;
        }
        else if(tmp > x) end--;
        else start++;
    }

    cout << cnt;
}
*/