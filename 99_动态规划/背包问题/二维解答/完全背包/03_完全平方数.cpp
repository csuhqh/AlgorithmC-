/**
 * https://leetcode.cn/problems/perfect-squares/
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 可以递归拆解。 (超时)
*/
class Solution {
public:
    int numSquares(int n) {
      //dp[i][j] 从 1~i个数中，相加等于j, 最少需要多个个
      int len = int(sqrt(n)) + 1; //+1是为了 比如输入是9, 我们范围是0~3， 一共4个数字
      // int len = n + 1;
      vector<vector<int>> dp(len + 1, vector<int>(n + 1, 0x3f3f3f3f));
      //dp[0][x] = 
      dp[0][0] = 0;
      dp[1][0] = 0;
      for(int i = 2; i <= len; ++i){
        int num = (i - 1) * (i - 1);
        for(int j = 0; j <= n; ++j){
          if(j >= num){
            dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - num] + 1);
            for(int k = 2; k * num <= j; ++k){
              dp[i][j] = min(dp[i][j], dp[i - 1][j - k * num] + k);
            }
          }else{
            dp[i][j] = dp[i - 1][j]; //不拿
          }
        }
      }
      return dp[len][n];
    }
};

