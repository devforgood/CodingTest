#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTestSort)
    {
    public:

        vector<int> solution(vector<int> array, vector<vector<int>> commands) {
            vector<int> answer;

            for (int i = 0; i < commands.size(); ++i)
            {
                vector<int> arr;
                arr.insert(arr.begin(), array.begin() + commands[i][0] - 1, array.begin() + commands[i][1]);
                sort(arr.begin(), arr.end());
                answer.push_back(arr[commands[i][2] - 1]);
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> array;
            array.push_back(1);
            array.push_back(5);
            array.push_back(2);
            array.push_back(6);
            array.push_back(3);
            array.push_back(7);
            array.push_back(4);

            vector<vector<int>> commands;
            vector<int> vec;
            vec.push_back(2);
            vec.push_back(5);
            vec.push_back(3);
            commands.push_back(vec);
            vec.clear();
            vec.push_back(4);
            vec.push_back(4);
            vec.push_back(1);
            commands.push_back(vec);
            vec.clear();
            vec.push_back(1);
            vec.push_back(7);
            vec.push_back(3);
            commands.push_back(vec);

            vector<int> result = solution(array, commands);

            Assert::AreEqual(result[0], 5);
            Assert::AreEqual(result[1], 6);
            Assert::AreEqual(result[2], 3);

        }


    };
}
