/**
 * https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
      vector<int> dp(nums.size(), 1);
      int result = 1;
      for(int i = 1; i < nums.size(); ++i){
        if(nums[i] > nums[i - 1]){
          dp[i] = dp[i - 1] + 1;
          result = max(result, dp[i]);
        }

      }
      return result;
    }
};

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        //dp[i] 为nums[i]为结尾的的串的最长连续递增序列
        vector<int> dp(nums.size(), 1);
        // dp[i] = dp[i - 1] + 1 or 1
        dp[0] = 1;
        int res = 1;
        for(int i = 1; i < nums.size(); ++i){
            if(nums[i] > nums[i - 1]){
                dp[i] = dp[i - 1] + 1;
            }else{
                dp[i] = 1;
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main(){
  return 0;
}