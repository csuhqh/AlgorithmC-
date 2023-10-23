/**
 * https://leetcode.cn/problems/climbing-stairs/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int climbStairs(int n) {
      //处理特殊情况
      if(n == 0) return 1;
      if(n <= 2) return n;
      //dp[i] 表示爬到第i个楼梯的排列数量
      vector<int> dp(n + 1); 
      dp[0] = 1;
      dp[1] = 1;
      dp[2] = 2;
      for(int i = 3; i <= n; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
      }
      return dp[n];
    }
};