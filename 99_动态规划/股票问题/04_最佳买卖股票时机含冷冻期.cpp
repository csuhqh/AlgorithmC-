/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
int maxProfit(vector<int>& prices) {
       if(prices.size()==1)
           return 0;
       vector<vector<int>> dp(prices.size(),vector<int>(2));
       dp[0][0] = -prices[0]; //第一天(买的情况)
       dp[0][1] = 0; //卖

       for(int i=1;i<prices.size();i++){
           if(i == 1){ //自己处理特殊情况
              dp[i][0]=max(dp[i-1][0],0-prices[i]); //要么买第0天的，要么买第一天的
              dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]);
              continue;
           }
           dp[i][0]=max(dp[i-1][0],dp[i-2][1]-prices[i]); //这里不能处理i == 1的情况
           dp[i][1]=max(dp[i-1][1],dp[i-1][0]+prices[i]);
       }
       return dp[prices.size()-1][1];
   }
};



//另一个理解
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0)); 
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for(int i = 1; i < prices.size(); ++i){
            if(i == 1){ //
                dp[i][0] = max(dp[i - 1][0], 0 - prices[i]); //特殊情况 (i - 2)无法处理i = 1的情况，手动处理
            }else{
                dp[i][0] = max(dp[i - 1][0], dp[i - 2][1] - prices[i]);  //买的情况
            }
            
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]); //卖的情况不收影响
        }
        return dp[prices.size() -1][1];
    }
};