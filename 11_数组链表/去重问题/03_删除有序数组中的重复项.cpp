/**
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array/submissions/?envType=study-plan-v2&envId=top-interview-150
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 两个指针i, j，如果相等，j往后移动
 * 如果不相等 i + 1 = j,  ++i;
 * 因为这里i是下标，所有长度为i + 1
*/
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 1) return nums.size();
        int i = 0, j = i + 1;
        for(; j < nums.size(); ++j){
            if(nums[i] != nums[j]){
                ++i;
                nums[i] = nums[j];
            }

        }
        nums.resize(i + 1);
        return i + 1;
    }
};