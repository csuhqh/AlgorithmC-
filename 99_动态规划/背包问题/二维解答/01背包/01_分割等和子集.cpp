/**
 * https://leetcode.cn/problems/partition-equal-subset-sum/
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 0/1背包
*/


class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int sum = 0;
      for(int i = 0; i < nums.size(); ++i){
        sum += nums[i];
      }
      if(sum % 2 == 1) return false;  
      int capacity = sum / 2;
      //定义dp数组 dp[i][j] 表示第i件物品，容量为j时的最大价值
      vector<vector<int>> dp(nums.size(), vector<int>(capacity + 1));
      //初始化(边界值)
      //dp[x][0] = 0, dp[0][x] = 0
      for(int i = 0; i <= capacity; ++i){
        dp[0][i] = i >= nums[0] ? nums[0] : 0;
      }
      //递推
      for(int i = 1; i < nums.size(); ++i){ //遍历每件物品
        for(int j = 1; j <= capacity; ++j){ //容量为1开始
          if(j >= nums[i]){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i]] + nums[i]);
          }else{
            dp[i][j] = dp[i - 1][j];
          }
          
        }
      }
      return sum- 2*dp[nums.size() -1][capacity] == 0;
    }
};