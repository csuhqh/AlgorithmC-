/**
 * https://leetcode.cn/problems/remove-element/submissions/?envType=study-plan-v2&envId=top-interview-150
*/
/**
 * 双指针，覆盖去重，O(n)
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return 0;
        int i = 0;
        for(int j = 0; j < nums.size();){
            //找出第一个不是val
            while(j < nums.size() && nums[j] == val){
                ++j;
            }
            if(j >= nums.size()){
                break;
            }else{
                nums[i] = nums[j];
                ++j;
                ++i;
            }
        }
        nums.resize(i);
        return i;
    }
};