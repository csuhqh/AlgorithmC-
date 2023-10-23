/**
 * https://leetcode.cn/problems/longest-increasing-subsequence/
*/

#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        //dp[i]是包括nums[i]的最长子序列，而不是，前n个数字的最长子序列
        vector<int> dp(nums.size(), 1);
        //
        int res = 1;
        for(int i = 1; i < nums.size(); ++i){
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j]){  //只有比上一个大，才可能产生更长的子序列
                    dp[i] = max(dp[i], dp[j] + 1); //获取所有子序列中最长的
                }
                if(res < dp[i]) res = dp[i];
            }
        }
        return res;
    }
};


int main(){
    vector<int> nums = {1,3,6,7,9,4,10,5,6};
    Solution solu;
    int res = solu.lengthOfLIS(nums);
    cout << res << endl;
    return 0;
}