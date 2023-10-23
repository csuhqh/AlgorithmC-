/**
 * https://leetcode.cn/problems/maximum-subarray/
*/
#include "iostream"
#include "vector"
using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        //长度为i的序列的最大连续和
        vector<int> dp(nums.size() + 1, 0);
        int res = nums[0];
        for(int i = 1; i <= nums.size(); ++i){
            dp[i] = max(dp[i -  1] + nums[i - 1], nums[i - 1]);
            if(dp[i] > res) res = dp[i];
            
        }
        return res;
    }
};




int main(){
    vector<int> nums = {3, -1, 4, 5};
    Solution solu;
    int res = solu.maxSubArray(nums);
    cout << res << endl;
    return 0;
}