/**
 * https://leetcode.cn/problems/maximum-length-of-repeated-subarray/
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 最长重复子数组 [子数组时连续的]
*/
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
      int result = 0;
      vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1));
      dp[0][0] = 0;
      for(int i = 1; i <= nums1.size(); ++i){
        for(int j = 1; j <= nums2.size(); ++j){
          if(nums1[i - 1] == nums2[j - 1]){ //当两个数字相同时，他的彼此更短的 + 1
            dp[i][j] = dp[i - 1][j - 1] + 1; //统计长度
          }
          result = max(result, dp[i][j]);
        }
      }
      return result;
    }
};

//优化
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        //最长重复连续序列
        vector<vector<int>> dp(nums1.size() + 1, vector<int>(nums2.size() + 1));
        dp[0][0] = 0;
        int res = 0;
        for(int i = 1; i <= nums1.size(); ++i){
            for(int j = 1; j <= nums2.size(); ++j){
                if(nums1[i - 1] == nums2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    
                }else{
                    dp[i][j] = 0;

                }
                res = max(res, dp[i][j]);
            }
        }
        return res;

    }
};

