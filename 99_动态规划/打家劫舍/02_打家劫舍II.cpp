/**
 * https://leetcode.cn/problems/house-robber-ii/
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 环形数组，打家劫舍
*/

//可以单独写一个函数，用作截取
class Solution {
public:
    int rob(vector<int>& nums) {
      if(nums.size() == 1) return nums[0];
      int len = nums.size();
      vector<int> dp(len - 1, 0); //定义dp数组
      // 0 ~ n - 1
      dp[0] = nums[0];
      dp[1] = max(nums[1], dp[0]);
      for(int i = 2; i < len - 1; ++i){
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
      }
      //1~n
      vector<int> dp1(len - 1, 0);
      dp1[0] = nums[1];
      dp1[1] = max(nums[2], dp1[0]);
      for(int i = 3; i < nums.size(); ++i){
        dp1[i - 1] = max(dp1[i - 3] + nums[i], dp1[i - 2]); //注意这里时i -1开始，因为dp[i]与nums[i]不对应
      }
      return max(dp[len - 2], dp1[len - 2]);
    }
};


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        return max(imp(nums, 0, n - 2), imp(nums, 1, n - 1));
    }

    int imp(vector<int>& nums, int start, int end){
        if(end - start + 1 == 1) return nums[start]; 
        vector<int> dp(end - start + 1);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for(int i = 2; i < end - start + 1; ++i){
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]); //注意这里时start + i
        }
        // cout << dp[end - start] << endl;
        return dp[end - start];
    }
};

int main(){

  return 0;
}