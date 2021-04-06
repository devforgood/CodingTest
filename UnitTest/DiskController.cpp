
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
    bool compare(vector<int> a, vector<int> b)
    {
        if (a[1] == b[1])
            return a[0] < b[0];
        else
            return a[1] < b[1];
    }

    TEST_CLASS(DiskController)
    {
    public:
        int solution2(vector<vector<int>> jobs) {
            int answer = 0;

            sort(jobs.begin(), jobs.end(), compare);
            
            int sum = 0;
            for (int i = 0; i < jobs.size(); ++i)
            {
                answer += jobs[i][1] + sum - jobs[i][0];
                sum += jobs[i][1];
            }

            answer /= jobs.size();

            return answer;
        }

        struct cmp {
            bool operator()(vector<int> a, vector<int> b) {
                return a.at(1) > b.at(1);
            }
        };

        int solution(vector<vector<int>> jobs) {
            //결과 저장용 변수, 인덱스 관리용, 시간체크용
            int answer = 0, j = 0, time = 0;
            //시간에 따른 오름차순으로 정렬
            sort(jobs.begin(), jobs.end());
            priority_queue<vector<int>, vector<vector<int>>, cmp> pq; //우선순위 큐 min heap
            //대기열이 없고 우선순위 큐가 빌때까지 반복
            while (j < jobs.size() || !pq.empty()) {
                //들어올 대기열이 남아있고, 들어올 대기열이 현재시간보다 작다면
                if (jobs.size() > j && time >= jobs[j][0]) {
                    //우선순위 큐에 추가
                    pq.push(jobs[j++]);
                    //인덱스 증가
                    //같은시간대에 다른작업이 더들어왔을 수 있으므로 다시 확인
                    continue;
                }
                //큐가 비어있지 않다면
                if (!pq.empty()) {
                    //시간에 이작업이 끝날때까지 걸리는 시간만큼 추가
                    time += pq.top()[1];
                    //작업시간에 대기 시간만큼 추가(현재시간 - 들어온 시간)
                    answer += time - pq.top()[0];
                    //작업이 끝났으므로 우선순위 큐에서 제거
                    pq.pop();
                }
                else //큐가 비어있다면 다음작업 시간으로 넘김
                    time = jobs[j][0];
            }
            return answer / jobs.size();//평균을 구해야하므로 총작업한 개수로 나눠줌
        }

        TEST_METHOD(TestMethod1)
        {
            vector<vector<int>> jobs = {{1, 3}, {3, 9}, {2, 6}};

            Assert::AreEqual(9, solution(jobs));

        }



    };
}
