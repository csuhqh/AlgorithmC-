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



int main(){
  return 0;
}