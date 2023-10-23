/**
 * https://leetcode.cn/problems/combination-sum-iv/description/
*/
/**
 * 题目叫: 组合总数，其实是错误
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 相当于可以爬的楼梯数量由nums提供
*/
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
      //dp[i]表示爬楼梯/排列为i的方案数量
      vector<uint32_t> dp(target + 1);
      dp[0] = 1;
      for(int i = 1; i <= target; ++i){
        for(int j = 0; j < nums.size(); ++j){
          // if(i < nums[j]) dp[i] = dp[i - 1];
          // else dp[i] += dp[i - nums[j]];
          if(i >= nums[j]) dp[i] += dp[i - nums[j]]; 
          else dp[i] += 0; //方案数 + 0
        }
      }
      return dp[target];
    }
};