/**
 * https://leetcode.cn/problems/sum-of-left-leaves/
*/
#include <bits/stdc++.h>
#include <cmath>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };
 class Solution {
public:
    int result = 0;
    int sumOfLeftLeaves(TreeNode* root) {
      sumLeft(root);
      return result;
    }

    void sumLeft(TreeNode* root){
      if(root == nullptr) return;
      if(root->left && root->left->left == nullptr && root->left->right == nullptr){ //左叶子
        result += root->left->val;
      }
      sumLeft(root->left);
      sumLeft(root->right);
    }
};