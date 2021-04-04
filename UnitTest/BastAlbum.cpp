
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
    struct album
    {
        int plays;
        int index;
    };

    bool compare(album i, album j)
    {
        if (i.plays == j.plays)
            return i.index < j.index;

        return i.plays > j.plays;
    }

    bool compare2(pair<string, int> a, pair<string, int> b)
    {
        return a.second > b.second;
    }

    TEST_CLASS(BastAlbum)
    {
    public:






        vector<int> solution(vector<string> genres, vector<int> plays) {
            vector<int> answer;

            unordered_map<string, vector<album>> map;
            vector<pair<string, int>> albums;
            unordered_map<string, int> cnt;
            album a;

            for (int i = 0; i < genres.size(); ++i)
            {
                a.plays = plays[i];
                a.index = i;
                cnt[genres[i]] += plays[i];
                map[genres[i]].push_back(a);
            }

            for (unordered_map<string, int>::iterator itr = cnt.begin(); itr != cnt.end(); ++itr)
            {
                albums.push_back(pair<string, int>(itr->first, itr->second));
            }

            sort(albums.begin(), albums.end(), compare2);


            for (vector<pair<string, int>>::iterator itr = albums.begin(); itr != albums.end(); ++itr)
            {
                vector<album>& v = map[itr->first];
                sort(v.begin(), v.end(), compare);
                for (int i = 0; i < 2 && i < v.size(); ++i)
                    answer.push_back(v[i].index);
            }




            return answer;
        }




        TEST_METHOD(TestMethod1)
        {
            vector<string> genres = { "classic", "pop", "classic", "classic", "pop" };
            vector<int> plays = { 500, 600, 150, 800, 2500 };

            vector<int> result = solution(genres, plays);
            Assert::AreEqual(4, result[0]);
            Assert::AreEqual(1, result[1]);
            Assert::AreEqual(3, result[2]);
            Assert::AreEqual(0, result[3]);
        }



    };
}
