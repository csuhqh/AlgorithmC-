/**
 * https://leetcode.cn/problems/coin-change/
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * 二维dp解决完全背包问题，可能带来O(n2)问题
*/
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[i][j] 表示i个硬币时，组成j的最少硬币个数
        vector<int> dp(amount + 1, 0x3f3f3f3f);
        dp[0] = 0;
        for(int i = 0; i < coins.size(); ++i){
          for(int j = 0; j <= amount; ++j){
            if(j >= coins[i]) dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            else dp[j] = min(dp[j], 0x3f3f3f3f);
          }
        }
        return dp[amount] == 0x3f3f3f3f ? -1: dp[amount];
    }
};