/**
 * https://leetcode.cn/problems/maximum-binary-tree/
*/
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* buildTree(vector<int>& nums, int start, int end){
      if(start > end) return nullptr;
      if(start == end) return new TreeNode(nums[start]);
      int maxVal = nums[start];
      int maxIndex = start;
      for(int i = start; i <= end; ++i){
        if(nums[i] > maxVal){
          maxIndex = i;
          maxVal = nums[i];
        }
      }
      TreeNode* root = new TreeNode(maxVal);
      root->left = buildTree(nums, start, maxIndex - 1);
      root->right = buildTree(nums, maxIndex + 1, end);
      return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
      if(nums.size() == 0) return nullptr;
      if(nums.size() == 1) return new TreeNode(nums[0]);
      int maxVal = nums[0];
      int maxIndex = 0;
      for(int i = 0; i < nums.size(); ++i){
        if(nums[i] > maxVal){
          maxIndex = i;
          maxVal = nums[i];
        }
      }
      TreeNode* root = new TreeNode(maxVal);
      root->left = buildTree(nums, 0, maxIndex - 1);
      root->right = buildTree(nums, maxIndex + 1, nums.size() - 1);
      return root;
    }
};