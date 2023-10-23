/**
 * url:https://leetcode.cn/problems/two-sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> twoSum(vector<int>& nums, int target){
            unordered_map<int, int> map;
            for(int i = 0; i < nums.size(); ++i){
                auto it = map.find(target - nums[i]);
                if(it != map.end()){ //存在
                    return {it->second, i};
                }
                //如果没找到匹配对，就把访问过的加入
                map.insert(pair<int, int>(nums[i], i));
            }
            return {};
        }
};


int main(){
    Solution solu;
    vector<int> nums = {2,7,11,15};
    int target = 9;

    vector<int> result = solu.twoSum(nums, target);

    cout << "result: ";

    //打印普通
    // cout << result << endl;
    //打印vector
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }

    cout << endl;
    return 0;
}

