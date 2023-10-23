/**
 * https://leetcode.cn/problems/squares-of-a-sorted-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {

        //方法一：利用内置函数
        // for(int i = 0; i < nums.size(); ++i){
        //     nums[i] = pow(nums[i], 2);
        // }
        // sort(nums.begin(), nums.end(), less<int>{});
        // return nums;

        //方法二: 双指针(最大的数字只可能出现在两端)
        // int n = nums.size();
        // vector<int> ans(n);
        // for (int i = 0, j = n - 1, pos = n - 1; i <= j;) {
        //     if (nums[i] * nums[i] > nums[j] * nums[j]) {
        //         ans[pos] = nums[i] * nums[i]; //最大的数字只可能出现在两端
        //         ++i;
        //     }
        //     else {
        //         ans[pos] = nums[j] * nums[j];
        //         --j;
        //     }
        //     --pos; 
        // }

        //方法三：负数部分，正数部分，都平方后，负数部分单调递减，正数部分单调递增
        int n = nums.size();
        int negative = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] < 0) {
                negative = i;
            } 
            nums[i] *= nums[i];
        }
        //有序序列归并
        vector<int> ans;
        int i = negative, j = negative + 1;
        while(i >= 0 && j < nums.size()){
            if(nums[i] > nums[j]){
                ans.push_back(nums[j]);
                ++j;
            }else{
                ans.push_back(nums[i]);
                --i;
            }
        }
        while(i >= 0){
            ans.push_back(nums[i]);
            --i;
        }
        while(j < nums.size()){
            ans.push_back(nums[j]);
            ++j;
        }
        return ans;
    }
};


int main(){
    Solution solu;
    vector<int> nums = {-4,-1,0,3,10};

    vector<int> res = solu.sortedSquares(nums);
    for(vector<int>::iterator it = res.begin(); it != res.end(); ++it){
        cout << *it << " ";
    }
    return 0;
}