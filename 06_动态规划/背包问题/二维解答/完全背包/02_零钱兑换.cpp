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
        int INF = 10004;
        // dp[i][j] 表示i个硬币时，组成j的最少硬币个数
        vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, INF));
         for(int i = 0; i < coins.size(); ++i){
           dp[i][0] = 0;
         }
        for (int i = 1; i <= coins.size(); ++i) {
            int num = coins[i - 1];
            for (int j = 0; j <= amount; ++j) {
                if(j >= num){
                  //拿一个
                  dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - num] + 1);
                  //拿多个
                  for(int k = 0; k * num <= j; ++k){
                    dp[i][j] = min(dp[i][j], dp[i - 1][j - k * num] + k);
                  }
                }else{
                  dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[coins.size()][amount] == INF ? -1 : dp[coins.size()][amount];
    }
};