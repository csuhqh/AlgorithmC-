/**
 * https://leetcode.cn/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
*/
/**
 * 快慢指针法
*/

//慢指针指向已经赋值的元素，快指针指向已经遍历的元素。
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() <= 2) return nums.size();
        int slow = 0, fast = 2;
        while(fast < nums.size()){
            if(nums[fast] == nums[slow]){ //这个很容易
                fast++;
            }else{ //这个
                nums[slow + 2] = nums[fast];
                ++slow;
                ++fast;
            }
        }
        return slow + 2;
    }
};