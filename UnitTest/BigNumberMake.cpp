
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


    TEST_CLASS(BigNumberMake)
    {
    public:

        string solution(string number, int k) {
            string answer = "";
            int length = number.length() - k;


            for (int i = 0; i < number.length() && k != 0;)
            {
                char max = '0' - 1;
                int index = 0;
                for (int j = i; j <= (k+i) && j< number.length(); ++j)
                {
                    if (number[j] > max)
                    {
                        max = number[j];
                        index = j;
                    }
                }

                answer += number[index];
                if (answer.length() == length)
                    break;

                k -= (index - i);
                i = index + 1;

                if (k == 0)
                {
                    answer += number.substr(index + 1, number.length() - (index + 1));
                }
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(string("7777"), solution("77777", 1));

            Assert::AreEqual(string("775841"), solution("4177252841", 4));
            Assert::AreEqual(string("94"), solution("1924", 2));
            Assert::AreEqual(string("3234"), solution("1231234", 3));
 
        }



    };
}
