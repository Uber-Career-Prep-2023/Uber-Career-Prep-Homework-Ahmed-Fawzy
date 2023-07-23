/*
n is number of elements so far

Time spent:       35 minutes
Technique:        2 heaps
Time complexity:  O(lg(n)) 
Space complexity: O(n)
*/

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

double findMedian(const priority_queue<int> &maxHeap, const priority_queue<int, vector<int>, greater<int>> &minHeap)
{
    if (maxHeap.size() == minHeap.size())
    {   
        double out = ((double)(maxHeap.top()) + (double)minHeap.top())/2;
        return out;
    }
    else
    {
        return maxHeap.top();
    }
}

void insertNumber(int num, priority_queue<int> &maxHeap, priority_queue<int, vector<int>, greater<int>> &minHeap)
{
    if (maxHeap.empty() || num <= maxHeap.top())
    {
        maxHeap.push(num);
    }
    else
    {
        minHeap.push(num);
    }

    if (maxHeap.size() > minHeap.size() + 1)
    {
        minHeap.push(maxHeap.top());
        maxHeap.pop();
    }
    else if (minHeap.size() > maxHeap.size())
    {
        maxHeap.push(minHeap.top());
        minHeap.pop();
    }
}

int main()
{
    priority_queue<int> maxHeap;                            
    priority_queue<int, vector<int>, greater<int>> minHeap; 

    insertNumber(1, maxHeap, minHeap);
    cout << "Median so far: " << findMedian(maxHeap, minHeap) << endl;

    insertNumber(11, maxHeap, minHeap);
    cout << "Median so far: " << findMedian(maxHeap, minHeap) << endl;

    insertNumber(4, maxHeap, minHeap);
    cout << "Median so far: " << findMedian(maxHeap, minHeap) << endl;

    insertNumber(15, maxHeap, minHeap);
    cout << "Median so far: " << findMedian(maxHeap, minHeap) << endl;

        insertNumber(12, maxHeap, minHeap);
    cout << "Median so far: " << findMedian(maxHeap, minHeap) << endl; 

    return 0;
}
