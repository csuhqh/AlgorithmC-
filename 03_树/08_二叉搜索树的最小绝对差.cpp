/**
 * https://leetcode.cn/problems/minimum-absolute-difference-in-bst/
*/

#include <bits/stdc++.h>
using namespace std;
/**
 * 二叉搜索树的中序变量是一个递增序列
*/

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
    int minVal = 0x3f3f3f3f;
    TreeNode* pre = nullptr;
    int getMinimumDifference(TreeNode* root) {
      if(root==nullptr) return 0;
      getMinimumDifference(root->left);
      if(pre && abs(pre->val - root->val) < minVal) minVal = abs(pre->val - root->val);
      pre = root;
      getMinimumDifference(root->right);
      return minVal;

    }
};