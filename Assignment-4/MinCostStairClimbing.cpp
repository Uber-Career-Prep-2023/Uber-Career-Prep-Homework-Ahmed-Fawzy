/*
Time spent:       25 minutes
Technique:        DP using arr of size n
Time complexity:  O(n) 
Space complexity: O(n)
*/

#include <iostream>
#include <vector>


using namespace std;

int minCost(vector<int> &costs)
{
    int n = costs.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return costs[0];

    vector<int> minCost(n, 0);
    minCost[0] = costs[0];
    minCost[1] = costs[1];

    for (int i = 2; i < n; ++i)
    {
        minCost[i] = costs[i] + min(minCost[i - 1], minCost[i - 2]);
    }

    return min(minCost[n - 1], minCost[n - 2]);
}

int main()
{
    vector<int> costs = {4, 1, 6, 3, 5, 8};
    int minTollRequired = minCost(costs);
    cout << "Minimum possible toll to climb the staircase: " << minTollRequired << endl;

    return 0;
}
