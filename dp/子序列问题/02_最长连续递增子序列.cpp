/**
 * https://leetcode.cn/problems/longest-continuous-increasing-subsequence/
*/
#include "iostream"
#include "vector"
#include "algorithm"
using namespace std;


class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        //dp[i]以nums[i]结尾的最长连续子序列长度
        vector<int> dp(nums.size(), 1);
        int maxL = 1;
        // int end = nums[0];
        for(int i = 1; i < dp.size(); ++i){
            if(nums[i] <= nums[i - 1]){
                dp[i] = 1;
            }else{
                dp[i] = dp[i - 1] + 1;
            }
            if(maxL < dp[i]) maxL = dp[i];
        }
        //暴力
        // int pointer = 0, after = 0;
        // int maxL = 1;
        // for(int i = 0; i < nums.size(); ++i){
        //     pointer = i;
        //     after = pointer + 1;
        //     int lci = 1;
        //     while(after < nums.size()){
        //         if (nums[pointer] < nums[after]){
        //             lci += 1;
        //             pointer++;
        //             after++;
        //         }else{
        //             break;
        //         }
        //     }
        //     if(lci > maxL){
        //         maxL = lci;
        //     }
        // }
        return maxL;

    }
};


int main(){
    vector<int> nums = {1,3,5,4,7};
    Solution solu;
    int res = solu.findLengthOfLCIS(nums);
    cout << res << endl;
    return 0;
}