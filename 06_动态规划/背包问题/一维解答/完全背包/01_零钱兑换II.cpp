/**
 * https://leetcode.cn/problems/coin-change-ii/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int change(int amount, vector<int>& coins) {
      vector<int> dp(amount + 1, 0);
      dp[0] = 1;
      for(int i = 0; i < coins.size(); ++i){
        int num = coins[i];
        for(int j = 0; j <= amount; ++j){
          if(j >= num) dp[j] = dp[j] + dp[j - num]; //不拿 + 拿
          // else dp[j] = dp[j];
        }
      }

      return dp[amount];
    }
};