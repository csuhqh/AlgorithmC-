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

class Solution {
public:
    int climbStairs(int n) {
        //dp[i] 有多少种方法可以到达第n阶
        //dp[n] = dp[n - 1] + dp[n - 2]
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= n; ++i){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};