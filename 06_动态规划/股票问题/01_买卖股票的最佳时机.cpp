/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
 */
#include <bits/stdc++.h>
using namespace std;

/**
 *  只能交易一次
*/

class Solution {
public:

    int maxProfit(vector<int>& prices) {
      //dp[i][0] 表示第0天持有时的最大，dp[i][1]表示第i天卖出的最大值
      vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
      //第一天
      dp[0][0] = -prices[0]; //第一天持有股票时的最大
      dp[0][1] = 0; //第二天出售股票后的最大 [其实暗含着可以在当天出售]
      for(int j = 1; j < prices.size(); ++j){ //从第二天开始推
        dp[j][0] = max(dp[j - 1][0], 0-prices[j]); //这里0表示，以前不可能卖过
        dp[j][1] = max(dp[j - 1][1], dp[j - 1][0] + prices[j] );
      }
      return dp[prices.size() - 1][1];
    }
};

int main() {
    return 0;
}