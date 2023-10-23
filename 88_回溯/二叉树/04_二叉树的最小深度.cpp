#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.cn/problems/maximum-depth-of-binary-tree/
*/


struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };


class Solution {
public:
    int dep{0};
    int minDep{0x3f3f3f3f};
    int minDepth(TreeNode* root) {
      if(root == nullptr) return 0;
      getD(root);
      return minDep;
    }
    void getD(TreeNode* root){
      if(root == nullptr) return;
      dep++;
      if(root->left == nullptr && root->right == nullptr)
        if(minDep > dep) minDep = dep;
      getD(root->left);
      getD(root->right);
      dep--;

    }
};

int main(){


  return 0;
}