
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


    TEST_CLASS(SteppingStone)
    {
    public:

        int solution(int distance, vector<int> rocks, int n) {
            int answer = 0;

            int min = 0;
            int max = distance;
            int mid;

            sort(rocks.begin(), rocks.end());
            rocks.push_back(distance);

            // 이분 탐색 알고리즘은 찍기 방식이다
            // 정답의 범위를 좁혀가는 방법으로 최소값, 최대값을 찾고 이분탐색으로 진행한다.
            // 여기서 최대값은 전체거리이고, 최소값은 0이다.
            // 추정된 값은 모든 조건을 만족해야 하므로 하나라도 틀리면 다음으로 넘어가는 식으로 진행한다.
            
            while (min <= max)
            {
                mid = (min + max) / 2;

                int last = 0;
                int skip = 0;
                int cur = 0;
                for (int i = 0; i < rocks.size(); ++i)
                {
                    cur = rocks[i] - last;
                    if (mid > cur )
                    {
                        ++skip;
                        if (skip > n)
                            break;
                    }
                    else
                    {
                        last = rocks[i];
                    }
                }
                if (mid > cur)
                {
                    max = mid - 1;
                }
                else
                {
                    if (answer < mid)
                        answer = mid;

                    min = mid + 1;
                }
            }


            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(4, solution(25, { 2, 14, 11, 21, 17 }, 2));


        }



    };
}
