/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 限定交易次数为k次，当天可以买，可以卖
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) { //限定股票交易次数
      vector<vector<int>> dp(prices.size(), vector<int>(5, 0));
      // dp[0][0] = 0; //当天没有任何操作
      dp[0][1] = -prices[0]; //第一次买入时
      dp[0][2] = 0; //第一次卖出
      dp[0][3] = -prices[0]; //第二次买入时 （表示必须改天如果完成第二次买入时的大金额）
      dp[0][4] = 0; //第二次卖出
      for(int i = 1; i < prices.size(); ++i){
        dp[i][1] = max(dp[i - 1][1], 0 - prices[i]);
        dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i]);
        dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i]);
        dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i]);
      }
      return dp[prices.size() - 1][2] > dp[prices.size() - 1][4]? dp[prices.size() - 1][2] : dp[prices.size() - 1][4];

    }
};

//优化
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(4, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        dp[0][3] = 0;
        for(int i = 1; i < prices.size(); ++i){
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }
        return max(dp[prices.size() - 1][1], dp[prices.size() - 1][3]);
    }
};