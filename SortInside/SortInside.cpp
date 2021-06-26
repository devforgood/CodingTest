#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <math.h>


using namespace std;



int main()
{
	string nums;
	cin >> nums;

	sort(nums.begin(), nums.end(), std::greater<char>());

	cout << nums;


}

