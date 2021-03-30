
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

using namespace std;

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(Immigration)
    {
    public:

        long long solution2(int n, vector<int> times) {
            long long answer = 0;



            map<long long, int> map;
            for (int i = 0; i < times.size(); ++i)
                map[times[i]] = 1;

            long long next_time;
            int next_count;
            while (n > 0)
            {
                answer = map.begin()->first;
                next_count = map.begin()->second + 1;
                next_time = map.begin()->first / map.begin()->second * next_count;
                map.erase(map.begin());

                map.insert(std::make_pair(next_time, next_count));
                --n;
            }



            return answer;
        }

        long long solution3(int n, vector<int> times) {

            
            long long answer = 0;

            sort(times.begin(), times.end());
            vector<int> counts;
           
            for(int i=0;i< times.size();++i)
                counts.push_back(1);

            vector<long long> list;
            long long next = times[0];
            long long cur;

            while(true)
            {
                for (int i = 0; i < times.size(); ++i)
                {
                    cur = times[i] * counts[i];
                    if (next >= cur)
                    {
                        list.push_back(cur);
                        if (list.size() == n)
                            return cur;
                        ++counts[i];
                        next = times[i] * counts[i];
                    }
                }


            }

            return answer;
        }


        long long solution4(int n, vector<int> times) {


            long long answer = 0;

            sort(times.begin(), times.end());
            vector<int> counts;

            for (int i = 0; i < times.size(); ++i)
                counts.push_back(1);

            
            long long next = 1000000000;
            long long cnt =0;

            while (true)
            {
                for (int i = 0; i < times.size(); ++i)
                {
                    answer = times[i] * counts[i];
                    if (next >= answer)
                    {
                        ++cnt;
                        if (cnt == n)
                            return answer;
                        ++counts[i];
                        next = min((long long)(times[i] * counts[i]), next);
                    }
                }


            }

            return answer;
        }

        long long solution(int n, vector<int> times) {
            long long answer = 0;
            sort(times.begin(), times.end());

            long long min = 1;
            long long max = (long long)(times[times.size() - 1]) * n;
            answer = max;
            long long mid;
            long long cnt;

            while (min <= max)
            {
                mid = (min + max) / 2;
                cnt = 0;
                for (auto t : times)
                    cnt += mid / t;

                if (cnt < n)
                {

                    min = mid + 1;
                }
                else
                {
                    if (answer >= mid)
                        answer = mid;

                    max = mid - 1;
                }

            }

            return answer;
        }

        TEST_METHOD(TestMethod1)
        {
            vector<int> times = { 7, 10 };

            Assert::AreEqual(28, (int)solution(6, times));
        }

        TEST_METHOD(TestMethod2)
        {
            vector<int> times = { 7, 10 };

            Assert::AreEqual(30, (int)solution(7, times));
        }

    };
}
