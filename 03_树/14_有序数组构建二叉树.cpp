/**
 * https://leetcode.cn/problems/convert-sorted-array-to-binary-search-tree/
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
      return buildTree(nums, 0, nums.size() - 1);

    }
    TreeNode* buildTree(vector<int>& nums, int l, int r){
      if(l > r) return nullptr; //一定要设置递归退出条件
      int mid = (l + r) / 2;
      TreeNode* root = new TreeNode(nums[mid]);
      root->left = buildTree(nums, l, mid - 1);
      root->right = buildTree(nums, mid + 1, r);
      return root;
    }
  
};