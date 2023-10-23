/**
 * https://leetcode.cn/problems/longest-increasing-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 错误思想1:
 * dp[i]为长度为i+ 1的最长递增序列。其实dp[i]是以nums[i]结尾的最长子序列
 * 
 * 错误思想2:
 * 只考虑nums[i] > nums[i - 1]的情况，其实就算nums[i] < nums[i - 1]虽然不会产生更长的序列，
 * 但是可以产生相等的徐磊
 * 0, 1, 0, 3, 2  // [0, 1, 3] 和[0, 1, 2]，如果那样考虑会造成dp[4] = 1; 其实等于3
*/

class Solution {
public:
    //错误思路: [1, 5, 1, 3] ==> 预期2，实际3
    //原因: dp[2] = dp[1] = 2; 但是由于判断 nums[3] > num[2]， 然后dp[3] = dp[2] + 1 = 3;就错误
    // int lengthOfLIS(vector<int>& nums) {
    //   vector<int> dp(nums.size(), 1); //初始化为1
    //   dp[0] = 1;
    //   for(int i = 1; i < nums.size(); ++i){
    //     //比前一个大
    //     if(nums[i] > nums[i - 1]){
    //       for(int j = 0; j < i; ++j){
    //         if(nums[j] < nums[i]){
    //           dp[i] = max(dp[i], dp[j] + 1);
    //         }
    //       }
    //     }else{ //比前一个小
    //       dp[i] = dp[i - 1];
    //     }
    //   }
    //   return dp[nums.size() - 1];
    // }
    //错误2
    // int lengthOfLIS(vector<int>& nums) {
    //   vector<int> dp(nums.size(), 1); //初始化为1
    //   dp[0] = 1;
    //   for(int i = 1; i < nums.size(); ++i){
    //     //比前一个大
    //     if(nums[i] > nums[i - 1]){
    //       for(int j = 0; j < i; ++j){
    //         if(nums[j] < nums[i]){
    //           dp[i] = max(dp[i], dp[j] + 1);
    //         }
    //       }
    //     }
    //     //如果比前一个小，则直接忽略（因为肯定不会产生更长的子序列）， !!!!错误思想
    //     //我们： dp[i]始终为以nums[i]为结尾的子序列的长度
    //   }
    //   for(int i = nums.size() - 1; i >= 0; --i){
    //     cout << nums[i] << endl;
    //   }
    //   for(int i = nums.size() - 1; i >= 0; --i){
    //     if(dp[i] != 1) return dp[i];
    //   }
    //   return 1;
    // }
    int lengthOfLIS(vector<int>& nums) {
      vector<int> dp(nums.size(), 1); //初始化为1
      dp[0] = 1;
      int res = 1;
      for(int i = 1; i < nums.size(); ++i){
          for(int j = 0; j < i; ++j){
            if(nums[j] < nums[i]){
              dp[i] = max(dp[i], dp[j] + 1);
            }
            res = max(res, dp[i]);
        }
        //如果比前一个小，则直接忽略（因为肯定不会产生更长的子序列）， !!!!错误思想
        //我们： dp[i]始终为以nums[i]为结尾的子序列的长度
      }
      return res;
    }
};

//优化
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i]表示以nums[i]为结尾的子序列长度
        vector<int> dp(nums.size(), 1);
        dp[0] = 1;
        int res = 1;
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){
                    dp[i] = max(dp[i], dp[j] + 1); //这里的dp[i] 还来自于dp[i], 所以需要初始化每一个dp[i]的初始值。
                }else{
                    dp[i] = max(dp[i], 1);
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};