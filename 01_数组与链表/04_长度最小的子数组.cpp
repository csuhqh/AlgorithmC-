/**
 * https://leetcode.cn/problems/minimum-size-subarray-sum/
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //无法使用动态规划，因为需要 >= target
        // vector<int> dp(target + 1, nums.size() + 1);
        // dp[0] = 0;
        // for(int i = 0; i < nums.size(); ++i){
        //     for(int j = target; j >= nums[i]; --j){
        //         dp[j] = min(dp[j], dp[j - nums[i]] + 1);
        //     }
        // }
        // return dp[target] > nums.size()? 0 : dp[target];
        //双指针法
        int i = 0, j = 0;
        int sum = 0;
        int len = 1000000;
        while(j < nums.size()){
            sum += nums[j];
            if(sum >= target){
                while(sum - nums[i] >= target){
                    sum -= nums[i];
                    ++i;
                }
                len = min(len, j - i);
            }
            ++j;
        }
        return len == 1000000 ? 0 : len + 1;
    }
};


int main(){
    Solution solu;
    vector<int> nums = {1,1,1,1,1,1,1,1};
    int target = 11;
    int res = solu.minSubArrayLen(target, nums);
    cout << res <<endl;
    return 0;
}