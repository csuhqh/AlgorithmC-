/**
 * https://leetcode.cn/problems/remove-element/submissions/?envType=study-plan-v2&envId=top-interview-150
*/
/**
 * 双指针，覆盖去重，O(n)
 * 模版题，秒杀
*/
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.size() == 0) return nums.size();
        int slow = 0, fast = 0;
        while(fast < nums.size()){
            if(nums[fast] == val){
                fast++;
            }else{
                nums[slow + 0] = nums[fast];
                ++slow;
                ++fast;
            }
        }
        nums.resize(slow);
        return slow;
    }
};