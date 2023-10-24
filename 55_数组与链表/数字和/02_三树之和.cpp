/**
 * https://leetcode.cn/problems/3sum/
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        unordered_set<int> seen; // 用于记录已经考虑过的元素
        
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n - 2; ++i) {
            // 跳过重复的元素
            if (seen.count(nums[i]))
                continue;
            
            int target = -nums[i];
            int left = i + 1;
            int right = n - 1;
            
            unordered_set<int> used; // 用于记录已经考虑过的元素对
            
            while (left < right) {
                int sum = nums[left] + nums[right];
                
                if (sum == target) {
                    result.push_back({nums[i], nums[left], nums[right]});
                    used.insert(nums[left]);
                    used.insert(nums[right]);
                    // 移动指针
                    ++left;
                    --right;
                } else if (sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
            
            seen.insert(nums[i]);
            seen.insert(used.begin(), used.end());
        }
        
        return result;
    }
};



