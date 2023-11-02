/**
 * https://leetcode.cn/problems/find-bottom-left-tree-value/
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
    int result;
    int dep{0};
    int maxDep{0};
    int findBottomLeftValue(TreeNode* root) {
      if(root->left==nullptr && root->right == nullptr)  return root->val;
      solu(root);
      return result;
    }
    void solu(TreeNode* root){
      if(root == nullptr) return;
      dep++; //更新深度
      if(dep > maxDep){//最底层
        maxDep = dep;
        if(root->left){
          maxDep++; //记录最深
          result = root->left->val;
        }else if(root->right){
          maxDep++;
          result = root->right->val;
        }else{
          result = root->val;
        }
        
      }
      solu(root->left);
      solu(root->right);
      dep--; //回溯

    }
};