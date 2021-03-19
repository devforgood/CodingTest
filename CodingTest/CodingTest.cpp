// CodingTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>

#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;

    queue<int> bridge;
    int bridge_weight = 0;
    int i = 0;
    for(int j=0;j<bridge_length;++j)
        bridge.push(0);


    do
    {


        ++answer;


        bridge_weight -= bridge.front();
        bridge.pop();

        if (i >= truck_weights.size())
        {
        }
        else if (bridge_weight + truck_weights[i] <= weight)
        {
            bridge.push(truck_weights[i]);

            bridge_weight += truck_weights[i];
            ++i;

        }
        else
        {
            bridge.push(0);
        }


    } while (bridge.size() != 0);


    return answer;
}
int main()
{
    vector<int> v;
    v.push_back(7);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);


    solution(2, 10, v);
    std::cout << "Hello World!\n";
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
