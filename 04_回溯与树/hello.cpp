#include <iostream>
#include <vector>

using namespace std;

class Solution{
  public:
  vector<vector<int>> result;
  vector<int> paths;
  int len;
  void backtrack(vector<int>& nums, int start) {
      paths.push_back(nums[start]);
      if (start == paths.size()) {
          result.push_back(paths);
          return;
      }
      // 
      for (int i = start; i < nums.size(); i++) {
          swap(nums[start], nums[i]);
          backtrack(nums, start + 1);
          swap(nums[start], nums[i]); // 回溯，恢复原状
          paths.pop_back();
      }
  }
// abc a --> bc 
  vector<vector<int>> permute(vector<int>& nums) {
      len = nums.size();
      for(int i = 0; i < ){

      }
      backtrack(nums, 0);
      return result;
  }
};



int main() {
    Solution solu;
    vector<int> nums = {1, 2, 3};
    vector<vector<int>> permutations = solu.permute(nums);
    for (const auto& p : permutations) {
        for (int num : p) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
