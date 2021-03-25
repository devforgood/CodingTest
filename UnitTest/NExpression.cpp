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

        int get_basic_number(int N, int cnt) {
            int res = 0;

            while (cnt > 0) {
                cnt -= 1;
                res += N * pow(10, cnt);
            }

            return res;
        }

        int solution(int N, int number) {
            // 허뎝님의 수정 피드백 -> 테스트 케이스가 바뀌면서 예외 사항을 추가해야 함.
            if (N == number) {
                return 1;
            }

            int answer = -1;

            const int MIN = 8;
            //1. [ {} x 8 ] 초기화
            auto s = vector<set<int>>(MIN);
            // 2. 각 set마다 기본 수 "N" * i 수 초기화
            int idx = 1;

            for (auto& x : s) {
                x.insert(get_basic_number(N, idx));
                idx += 1;
            }

            //3. n 일반화
            //   { 
            //       "n" * i, 
            //       1번 set 사칙연산 n-1번 set, 
            //       2번 set 사칙연산 n-2번 set, 
            //       ...
            //       n-1번 set 사칙연산 1번 set, 
            //    } 
            // number를 가장 최소로 만드는 수 구함.
            for (int i = 1; i < MIN; i++) {
                for (int j = 0; j < i; j++) {
                    for (const auto& op1 : s[j]) {
                        for (const auto& op2 : s[i - j - 1]) {
                            s[i].insert(op1 + op2);
                            s[i].insert(op1 - op2);
                            s[i].insert(op1 * op2);

                            if (op2 != 0)
                                s[i].insert(op1 / op2);
                        }
                    }
                }

                if (s[i].find(number) != s[i].end()) {
                    answer = i + 1;
                    break;
                }
            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            Assert::AreEqual(4, solution(5, 12));
        }


    };
}
