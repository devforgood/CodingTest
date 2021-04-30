
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
                // 4���� Ŭ�ν��� �������� �߰� ������ ����(0.5, 0.5)�� ǥ���ϱ� ���� ������ �ι�� ����Ѵ�.
                for (int j = 0; j < 2; ++j)
                {
                    int next_x = x + direction[arrows[i]][0];
                    int next_y = y + direction[arrows[i]][1];

                    // ���� ����� ������ ���� ������ �ٽ� �湮���� ���
                    // ������ ������ �ٳణ ���� ����, ���� ������� ��츸
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
