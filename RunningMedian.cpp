#include <iostream>
#include <queue>

using namespace std;

priority_queue<int> min_heap;
priority_queue<int, vector<int>, greater<int>> max_heap;

void push(int number)
{
    if (max_heap.empty() || number >= max_heap.top()) 
    {
        max_heap.push(number);
    }
    else {
        min_heap.push(number);
    }

    if (max_heap.size() < min_heap.size()) 
    {
        max_heap.push(min_heap.top());
        min_heap.pop();
    }
    else if (max_heap.size() > min_heap.size() + 1) 
    {
        min_heap.push(max_heap.top());
        max_heap.pop();
    }

    // max_heap와 min_heap의 크기가 같다면 총 개수는 짝수이다.
    if (max_heap.size() == min_heap.size()) 
    {
        cout << ((float)max_heap.top() + (float)min_heap.top()) * 0.5f << endl;
    }
    else 
    {
        cout << max_heap.top() << endl;
    }
}

int pop()
{
    return 0;
}

int main()
{
    push(3);
    push(2);
    push(4);
    push(1);
}
