#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(TargetNumber)
    {
    public:

        int doTargetNumber(vector<int> numbers, int target, int index, bool sum, int total)
        {

            int cur_total = 0;
            if (sum)
            {
                cur_total = total + numbers[index];
            }
            else
            {
                cur_total = total - numbers[index];
            }

			if (index == numbers.size() - 1)
			{
				if (cur_total == target)
					return 1;
				else
					return 0;

			}

            
            int ret = 0;
            ret += doTargetNumber(numbers, target, index + 1, true, cur_total);
            ret += doTargetNumber(numbers, target, index + 1, false, cur_total);
            return ret;
        }

        int solution(vector<int> numbers, int target) {
            int answer = 0;

            answer = doTargetNumber(numbers, target, 0, true, 0);
            answer  += doTargetNumber(numbers, target, 0, false, 0);
            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> numbers = { 1, 1, 1, 1, 1 };
            Assert::AreEqual(5, solution(numbers, 3));
        }


    };
}
