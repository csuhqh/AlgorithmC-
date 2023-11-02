/**
 * https://leetcode.cn/problems/3sum/
*/
/**
 * 外层固定的点的去重和内部是不一样的
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end()); //默认less, 升序
        for(int left = 0; left < nums.size(); ++left){
            //对left进行去重（考虑不同的left起点，包括的数字个数不一样）
            //考虑[-1, -1, 0, 1, 2] 有2个，
            //left起点一: -1, -1, 0, 1, 2
            //left起点2: -1, 0, 1, 2， 显然前者考虑的更多，考虑了前者不用考虑后者
            if(left > 0 && nums[left] == nums[left - 1]) continue; //去重
            int right = nums.size() - 1;
            for(int i = left + 1; i < right;){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum > 0){
                    right--;
                }else if(sum < 0){
                    ++i;
                }else{
                    res.push_back({nums[left], nums[i], nums[right]});
                    //确保得到不同的三元组。真正的去重
                    //对i进行去重
                    while(i < right && nums[i] == nums[i + 1]) ++i;
                    while(i < right && nums[right] == nums[right - 1]) --right;
                    ++i; 
                    // --right; //可写可不写
                }
            }
        }
        return res;
    }
};


