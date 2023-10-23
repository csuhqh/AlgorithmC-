/**
 * https://leetcode.cn/problems/target-sum/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      //求背包容量
      int sum = 0;
      for(int i = 0; i < nums.size(); ++i) sum += nums[i];
      if((target + sum) % 2 == 1) return 0; //背包容量为小数
      int capacity = (target + sum) / 2;
      if(capacity < 0) return 0;
      //dp[i][j] i个物品, 值为j时的方法数量
      vector<vector<int>> dp(nums.size(), vector<int>(capacity + 1, 0));
      //初始化(第0个物品已经遍历完毕)
      int count = 0;
      for(int i = 0; i < nums.size(); ++i)
        if(nums[i] == 0)  count++;
      for(int i = 0; i <= nums.size(); ++i){
        dp[i][0] = count;
      }
      dp[0][0] = 1;
      for(int i = 1; i < nums.size(); ++i){
        int num = nums[i - 1];
        for(int j = 0; j <= capacity; ++j){
          if(j >= num) dp[i][j] = dp[i-1][j] + dp[i - 1][j - num];  //并没有j + 1, 所以只要初始化一束
          else dp[i][j] = dp[i - 1][j];
        }
      }
      return dp[nums.size() - 1][capacity];
    }
};