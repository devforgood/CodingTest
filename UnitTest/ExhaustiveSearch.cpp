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
    TEST_CLASS(ExhaustiveSearch)
    {
    public:

        int solution2(string numbers) {
            int answer = 0;
            int n = numbers.size();

            for (int r = 1; r <= n; ++r)
            {
                do
                {
                    if (numbers[0] != '0')
                    {
                        if (isPrime(atoi(numbers.substr(0, r).c_str())))
                        {
                            ++answer;
                        }
                    }

                    reverse(numbers.begin() + r, numbers.end());

                } while (next_permutation(numbers.begin(), numbers.end()));
            }

            return answer;
        }

        bool isPrime(int n) {
            if (n <= 1) {
                return false;
            }

            for (int i = 2; i <= sqrt(n); i++) {
                if ((n % i) == 0) {
                    return false;
                }
            }

            return true;
        }

        void clearNumberCount(int* number_count, int size)
        {
            for (int i = 0; i < size; ++i)
            {
                number_count[i] = 0;
            }
        }

        void numCount(string numbers, int* number_count)
        {
            for (int i = 0; i < numbers.size(); ++i)
                ++number_count[numbers[i] - '0'];
        }

        int solution(string numbers) {
            int answer = 0;
            sort(numbers.begin(), numbers.end(), greater<char>());
            int num = atoi(numbers.c_str());

            int num_cnt[10];
            int num_cnt2[10];

            clearNumberCount(num_cnt, 10);
            numCount(numbers, num_cnt);

            string cur_number;
            int is_break;
            for (int i = 2; i <= num; ++i)
            {
                cur_number = to_string(i);
                clearNumberCount(num_cnt2, 10);
                numCount(cur_number, num_cnt2);
                is_break = false;
                for (int j = 0; j < 10; ++j)
                {
                    if (num_cnt[j] < num_cnt2[j])
                    {
                        is_break = true;
                        break;
                    }
                }

                if (is_break)
                    continue;

                if (isPrime(i))
                    ++answer;
            }


            return answer;
        }

        TEST_METHOD(TestMethod1)
        {

            Assert::AreEqual(3, solution("17"));
        }


    };
}
