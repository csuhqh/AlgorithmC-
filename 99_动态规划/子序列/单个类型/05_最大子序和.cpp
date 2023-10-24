/**
 * https://leetcode.cn/problems/maximum-subarray/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      vector<int> dp(nums.size(), 0);
      dp[0] = nums[0];
      int result = dp[0];
      for(int i = 1; i < nums.size(); ++i){
        // dp[i] = dp[i - 1] + nums[i];
        dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        result = max(result, dp[i]);
      }
      return result;
    }
};
//优化
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp[i]表示以Nums[i]为结尾的连续子数组的最大和, 因此不一定是dp[len - 1]最大
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        int res = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            res = max(res, dp[i]);
        }
        return res;
    }
};

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //dp[i]为以nums[i]结尾的最大和
        //dp[i] = (dp[i - 1] or 0) + nums[i]
        vector<int> dp(nums.size(), 0);
        int res = nums[0];
        dp[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i){
            if(dp[i - 1] > 0){
                dp[i] = dp[i - 1] + nums[i];
            }else{
                dp[i] = nums[i];
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};