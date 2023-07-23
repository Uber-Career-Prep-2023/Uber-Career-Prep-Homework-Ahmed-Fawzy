/*
n is number of denominations
k is target number

Time spent:       30 minutes
Technique:        DP using an array
Time complexity:  O(n*k)
Space complexity: O(k)
*/

#include <iostream>
#include <vector>

int cointChange(std::vector<int>& denom, int target) {
    std::vector<int> dp(target + 1, 0);
    dp[0] = 1;

    for (int coin : denom) {
        for (int i = coin; i <= target; ++i) {
            dp[i] += dp[i - coin];
        }
    }

    return dp[target];
}

int main() {
    std::vector<int> denominations = {2, 5, 10}; 
    int targetSum1 = 20; 
    int targetSum2 = 15; 

    int ways1 = cointChange(denominations, targetSum1);
    int ways2 = cointChange(denominations, targetSum2);
    std::cout << "Output for test 1: " << ways1 << std::endl;
    std::cout << "Output for test 2: " << ways2 << std::endl;

    return 0;
}
