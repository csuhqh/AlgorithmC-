/**
 * https://leetcode.cn/problems/coin-change-ii/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int change(int amount, vector<int>& coins) {

      vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, 0));

      for(int i = 0; i <= coins.size(); ++i){
        dp[i][0] = 1;
      }
      // dp[0][0] = 1;
      for(int i = 1; i <= coins.size(); ++i){
        int num = coins[i - 1];
        for(int j = 0; j <= amount; ++j){
          //容易懂的写法
          if(j >= num){ //取一个或多个
            //取一个的情况
            dp[i][j] = dp[i - 1][j] + dp[i - 1][j - num]; 
            //取2个以上
            for(int k = 2; k * num <= j; ++k){ //放1...k/num 个
              dp[i][j] += dp[i - 1][j - k * num]; 
            }
          }else{ //不取
            dp[i][j] = dp[i - 1][j];
          }
          //错误接法:
          // for(int k = 0; k * num <= j; ++k){
          //   if(j >= k * num) dp[i][j] = dp[i -  1][j] + dp[i - 1][j - k * num]; //不拿的组合数 + 拿的组合数
          //   else dp[i][j] = dp[i - 1][j];
          // } 
          //优化写法:
          // dp[i][j] = dp[i -1][j];
          // for(int k = 1; k * num <= j; ++k){
          //    dp[i][j] += dp[i - 1][j - k * num];
          // }

        }
      }
      return dp[coins.size()][amount];
    }
};