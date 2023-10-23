/**
 * https://leetcode.cn/problems/unique-paths-ii/
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 注意初始化过程中，可能也会碰到特殊条件
*/
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      if(obstacleGrid[0][0] == 1) return 0;
      if(obstacleGrid[m - 1][n - 1] == 1) return 0;
      vector<vector<int>> dp(m, vector<int>(n));
      //需要初始化（初始化过程中也要注意特殊情况）
      for(int i = 0; i < m; ++i){
        if(obstacleGrid[i][0] == 1) break;
        dp[i][0] = 1;
      }
      for(int i = 0; i < n; ++i){
        if(obstacleGrid[0][i] == 1) break;
        dp[0][i] = 1;
      }
      for(int i = 1; i < m; ++i){
        for(int j = 1; j < n; ++j){
          // if(obstacleGrid[i - 1][j] == 0 && obstacleGrid[i][j - 1] == 0){
          //   dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
          // }else if(obstacleGrid[i - 1][j] == 0){
          //   dp[i][j] = dp[i - 1][j];
          // }else if(obstacleGrid[i][j - 1] == 0){
          //   dp[i][j] = dp[i][j - 1];
          // }else{
          //   dp[i][j] = 0;
          // }
          if(obstacleGrid[i][j] == 1) continue;
          dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }

      }
      return dp[m - 1][n - 1];
      

    }
};