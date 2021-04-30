
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
    TEST_CLASS(RoomCount)
    {
    public:

        int solution(vector<int> arrows) {
            int answer = 0;
            vector<vector<int>> direction = { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };
            map<pair<int, int>, bool> node;
            map<pair<pair<int, int>, pair<int, int>>, bool> edge;

           

            int x = 0;
            int y = 0;
            node[{x, y}] = true;
            for (int i = 0; i < arrows.size(); ++i)
            {
                // 4점을 클로스로 만났을때 중간 지점인 정점(0.5, 0.5)를 표현하기 위해 정점을 두배로 계산한다.
                for (int j = 0; j < 2; ++j)
                {
                    int next_x = x + direction[arrows[i]][0];
                    int next_y = y + direction[arrows[i]][1];

                    // 방이 생기는 기준인 이전 정점에 다시 방문했을 경우
                    // 간선은 이전에 다녀간 것은 제외, 새로 만들어진 경우만
                    if (node[{next_x, next_y}] == true && edge[{ {x, y}, { next_x, next_y }}] == false)
                    {
                        ++answer;
                    }

                    node[{next_x, next_y}] = true;
                    edge[{ {x, y}, { next_x, next_y }}] = true;
                    edge[{ { next_x, next_y }, { x, y }}] = true;
                    x = next_x;
                    y = next_y;
                }
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(3, solution({ 6, 6, 6, 4, 4, 4, 2, 2, 2, 0, 0, 0, 1, 6, 5, 5, 3, 6, 0 }));
        }
    };
}
