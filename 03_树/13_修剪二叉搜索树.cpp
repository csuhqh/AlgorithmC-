/**
 * https://leetcode.cn/problems/trim-a-binary-search-tree/
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
    TreeNode* trimBST(TreeNode* root, int low, int high) {
      if(root == nullptr) return root;
      if(root->val < low){ //那么左边的都会比low小
        TreeNode *right = trimBST(root->right, low, high);
        return right;
      }
      if(root->val > high){
        TreeNode* left = trimBST(root->left, low, high);
        return left;
      }


      
      root->left = trimBST(root->left, low, high);
      root->right = trimBST(root->right, low, high);
      return root;
    }
};
