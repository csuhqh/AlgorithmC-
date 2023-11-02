/**
 * https://leetcode.cn/problems/VvJkup/discussion/
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return res;
    }
    void backtrack(vector<int>& nums){
        if(path.size() == nums.size()){
            res.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); ++i){
            if(find(path.begin(), path.end(), nums[i]) != path.end()) continue;
            path.push_back(nums[i]);
            backtrack(nums);
            path.pop_back();
        }

    }
};