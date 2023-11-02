/**
 * https://leetcode.cn/problems/two-sum/
*/
/**
 * 此题目结合哈希表
*/


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); ++i){
            map.insert(make_pair(nums[i], i));
        }
        for(int i = 0; i < nums.size(); ++i){
            auto it = map.find(target - nums[i]);
            if(it != map.end() && i != it->second){
                return {i, it->second};
            }
        }
        return {};
    }
};