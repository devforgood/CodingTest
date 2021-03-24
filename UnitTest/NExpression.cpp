#include "pch.h"
#include "CppUnitTest.h"
#include <iostream>

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <list>
#include <set>

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(NExpression)
    {
    public:

        int DP(set<int> & input_list, set<int> & output_list, int index, int N, int number)
        {
            output_list.clear();

            for (set<int>::iterator itr = input_list.begin(); itr != input_list.end(); ++itr)
            {
                int a = (*itr) + N;
                if (a == number)
                    return true;
                output_list.insert(a);

                int b = (*itr) - N;
                if (b == number)
                    return true;
                output_list.insert(b);

                int c = (*itr) * N;
                if (c == number)
                    return true;
                output_list.insert(c);

                int d = (*itr) / N;
                if (d == number)
                    return true;
                output_list.insert(d);

                int e = (*itr)*10 + N;
                if (e == number)
                    return true;
                output_list.insert(e);

                int f = N - (*itr);
                if (f == number)
                    return true;
                output_list.insert(f);

                if ((*itr) != 0)
                {
                    int g = N / (*itr);
                    if (g == number)
                        return true;
                    output_list.insert(g);
                }

            }
            


            return false;
        }

        int solution(int N, int number) {
            int answer = 0;

            if (N == number)
                return 1;

            set<int> input_list = { N };
            set<int> ouput_list;
            int i;
            for (i = 2; i < 9; ++i)           
            {
                if (DP(input_list, ouput_list, i, N, number))
                    return i;

                input_list = ouput_list;
            }

            if (i == 9)
                answer = -1;
            else
                answer = i;


            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(4, solution(5, 12));
        }


    };
}
