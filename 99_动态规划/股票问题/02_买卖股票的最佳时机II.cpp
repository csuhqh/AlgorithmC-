/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 不限定股票交易次数
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
      dp[0][0] = -prices[0];
      dp[0][1] = 0; //其实暗含着可以当天出售
      for(int i = 1; i < prices.size(); ++i){
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]); //今天持有股票的钱会受昨天的影响
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
      }
      return dp[prices.size() - 1][1];
    }
};

int main(){

  return 0;
}