#include <bits/stdc++.h>
using namespace std;


/**
 * 第一步: 确定dp含义
 * 第二步: 确定dp递推公式
 * 第二步，根据递推公式写初始化条件。
 * 第三步: 确定边界条件
*/
class Solution {
public:
    int uniquePaths(int m, int n) {

      vector<vector<int>> dp(m, vector<int>(n));
      //需要初始化
      for(int i = 0; i < m; ++i){
        dp[i][0] = 1;
      }
      for(int i = 0; i < n; ++i){
        dp[0][i] = 1;
      }
      for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
          dp[i][j] = dp[i - 1][j] +dp[i][j - 1];
        }

      }
      //已知道dp , 
      return dp[m - 1][n - 1];
    }
};