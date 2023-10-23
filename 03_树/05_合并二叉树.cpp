/**
 * https://leetcode.cn/problems/merge-two-binary-trees/
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
  /**
   * 已有树的合并题目，用树原本的节点
  */
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
      if(!root1 && !root2) return nullptr;
      if(root1 && !root2) return root1;
      if(!root1 && root2) return root2;
      // TreeNode* root = new TreeNode(root1->val + root2->val);
      root1->val += root2->val;
      root1->left = mergeTrees(root1->left, root2->left);
      root1->right = mergeTrees(root1->right, root2->right);
      return root1;
      // return root;
    }
};