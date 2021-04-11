
#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <queue>
#include <list>
#include <set>
#include <map>
#include <unordered_map>
#include <stack>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{


    TEST_CLASS(Joystick)
    {
    public:
        int solution2(string name) {
            int answer = 0;
            char start = 'A';
            char end = 'Z';

            int distance = 0;
            for (int i = 0; i < name.size();)
            {
                if (name[i] == start)
                {
                    int index = 0;
                    distance = 0;
                    for (int j = i; j < name.size(); ++j)
                    {
                        if (name[j] != start)
                        {
                            index = j;
                            break;
                        }
                        ++distance;
                    }

                    distance = min(((int)name.size() - index + i -2), distance);
                    i = index;
                    answer += distance;
                }
                else
                {

                    distance = name[i] - start;
                    distance = min((end - name[i] + 1), distance);

                    ++i;
                    answer += distance;

                    if (i == name.size())
                        break;

                    answer += 1;
                }
            }


            return answer;
        }

        int solution2(string name)
        {
            int answer = 0;
            char start = 'A';
            char end = 'Z';
            int distance = 0;

            vector<int> diff;
            for (int i = 0; i < name.size(); ++i)
            {
                if (name[i] != start)
                    diff.push_back(i);
                else if(i==0)
                    diff.push_back(0);
            }

            int cursor = 0;
            int next_cursor = 0;
            int left = 1;
            int right = diff.size() - 1;
            for (int i = 0; i < diff.size(); ++i)
            {
                if (i + 1 != diff.size())
                {
                    if (cursor > diff[right])
                    {
                        if (cursor - diff[right] <= name.size()  - cursor + diff[left])
                        {
                            answer += cursor - diff[right];
                            next_cursor = diff[right];
                            --right;
                        }
                        else
                        {
                            answer += name.size() - cursor + diff[left];
                            next_cursor = diff[left];
                            ++left;
                        }

                    }
                    else
                    {
                        if (diff[left] - cursor <= name.size() - diff[right] + cursor)
                        {
                            answer += diff[left] - cursor;
                            next_cursor = diff[left];
                            ++left;
                        }
                        else
                        {
                            answer += name.size() - diff[right] + cursor;
                            next_cursor = diff[right];
                            --right;
                        }
                    }
                }

                distance = name[cursor] - start;
                distance = std::min((end - name[cursor] + 1), distance);
                answer += distance;
                cursor = next_cursor;
            }




            return answer;
        }


        //조이스틱을 움직일수있는 최소경로에 대해서는, 
        // (i) 원점에서 i번째를 먼저 갔다가, 원점으로 돌아가고 역주행하여 next_i번째에 도착한다. 
        // (ii) 원점에서 역주행해서 next_i번째에 먼저 갔다가, 원점으로 정주행해서 돌아가고 i번째에 도착한다, 
        // 둘중 하나이다. for문으로 각각의 i에서 그에 상응하는 next_i번째로 가는 길을 탐색할때마다,
        //  원점의 관점에서 시작해서 위의 2가지 방법 중 최소경로를 탐색하는 과정(전체적인 min을 찾는 과정)을 하게됨.
        // 최종 left_right값은 어딘가의 i에서 그것의 next_i로 이동할때 최소경로인 (i)또는 (ii)중 하나의 모습일 것임.
        // (즉, i또는 ii의 모습만 나옴. 최소경로니까 i했다가 ii했다가 i했다가 ii했다가 i하는 모습같은건 안나옴). 
        // 예를 들어서, [A 2개]C[A 100개]C[A 1억개]C[A 2개] 라고 생각해보면, 역주행해서 C찍었다가 원점으로 돌아가고, [A1억개] 앞에있는 C까지 정주행한 경로가 제일 저렴한 최종 left_right로 나옴.
        int solution(string name) {
            int LUT[] = { 0,1,2,3,4,5,6,7,8,9,10,11,12,13,12,11,10,9,8,7,6,5,4,3,2,1 };

            int answer = 0;
            for (auto ch : name)
                answer += LUT[ch - 'A'];
            int len = name.length();
            int left_right = len - 1;
            for (int i = 0; i < len; ++i) {
                int next_i = i + 1;
                while (next_i < len && name[next_i] == 'A')
                    next_i++;
                left_right = min(left_right, i + len - next_i + min(i, len - next_i));
            }
            answer += left_right;
            return answer;
        }
        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(11, solution("JAZ"));
			Assert::AreEqual(11, solution("ABABAAAAABA"));

			Assert::AreEqual(56, solution("JEROEN"));


			Assert::AreEqual(23, solution("JAN"));


        }



    };
}
