
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


    TEST_CLASS(Carpet)
    {
    public:

        vector<int> solution2(int brown, int yellow) {
            vector<int> answer;

            int v = brown + yellow;
            for (int i = 2; i < 5000; ++i)
            {
                for (int j = 2; j <= i; ++j)
                {
                    if (v == i * j 
                        && (i-2)*(j-2) == yellow // 안쪽 블럭 수는 상하, 좌우 갯수를 제외하고 곱했을 때와 동일
                        )
                    {
                        return answer = { i, j };
                    }
                }
            }
            return answer;
        }

        vector<int> solution(int brown, int red) {
            // 이해가 안감
            //w: 가로, h: 세로, w * h = brown + red, (w-2) * (h-2) = red, 두 식을 red를 대입해서 연립방정식으로 풀어보면
            //, w = brown/2 + 2 - h, h = n(단, n은 자연수) 가 되는데, h값이 변함에 따라서 w값은 자연스럽게 바뀌어서 그래요. h가 1 늘어난다는 것은 w가 1 줄어드는 것과 같죠
            int len = brown / 2 + 2;

            int w = len - 3;
            int h = 3;

            while (w >= h) {
                if (w * h == (brown + red)) break;

                w--;
                h++;
            }

            return vector<int>{w, h};
        }

        TEST_METHOD(TestMethod1)
        {
            auto result = solution(10, 2);
            Assert::AreEqual(4, result[0]);
            Assert::AreEqual(3, result[1]);

            result = solution(8, 1);
            Assert::AreEqual(3, result[0]);
            Assert::AreEqual(3, result[1]);

            result = solution(24, 24);
            Assert::AreEqual(8, result[0]);
            Assert::AreEqual(6, result[1]);

            result = solution(50, 22);
            Assert::AreEqual(24, result[0]);
            Assert::AreEqual(3, result[1]);

        }



    };
}
