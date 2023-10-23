/**
 * https://leetcode.cn/problems/integer-break/
*/
/**
 * 
*/

#include <bits/stdc++.h>
using namespace std;

/**
 * 这里dp[i]表示拆分数字i，数字乘积的最大值。
 * dp[i] = (i - j) * j;
 * 但是 i 与 dp[i] 相比， dp[i]和i的大小不一样。
 * 
*/

class Solution {
public:
    int integerBreak(int n) {
      //1. dp[i] 为n, dp[i]为乘积最大化
      vector<int> dp(n + 1);
      dp[2] = 1 * 1;
   
      //2. 确定递推公式
      for(int i = 3; i <= n; ++i){

        for(int j = 1; j < i - 1; ++j){
          // dp[i] = max({dp[i], (i - j) * j, dp[i - j] * j}); //选出最大的
          dp[i] = max(dp[i], max(dp[i - j], i - j) * max(dp[j], j));
        }


      }
      return dp[n];

    }
};