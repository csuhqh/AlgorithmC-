/**
 * https://leetcode.cn/problems/path-sum/
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
    bool result{false};
    int targetSum{0};
    int curSum{0};
    bool hasPathSum(TreeNode* root, int targetSum) {
      this->targetSum = targetSum;
      solu(root);
      return result;
    }
    void solu(TreeNode* root){
      if(root == nullptr || result == true) return;
      curSum += root->val;
      if(root->left == nullptr && root->right == nullptr){
        if(curSum == targetSum){
          result = true;
          return;
        }
      }
      solu(root->left);
      solu(root->right);
      curSum -= root->val;


    }
};
