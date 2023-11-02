class Solution {
public:

    vector<int> path;
    vector<vector<int>> res;
    vector<bool> visited;
    int k;

    void backtrack(vector<int>& nums){
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        //同一层内不重复
        unordered_set<int> levelVisited;
        for(int i = 0; i < nums.size(); ++i){
            if(visited[i]) continue; //去重不同层(index去重)，例如在[2, 2]中，这两个2是可以出现在不同层的。
            if(levelVisited.find(nums[i]) != levelVisited.end()) continue; //去重同一层(值去重)，同一层不能用相同的值

            levelVisited.insert(nums[i]);
            visited[i] = true;
            path.push_back(nums[i]);
            backtrack(nums);
            visited[i] = false;
            path.pop_back();
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        this->k = nums.size();
        visited.resize(nums.size(), false);
        backtrack(nums);
        return res;
    }
};