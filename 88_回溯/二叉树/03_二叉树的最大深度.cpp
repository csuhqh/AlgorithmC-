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
    int maxDep{0};
    int maxDepth(TreeNode* root) {
      getD(root);
      return maxDep;
    }
    void getD(TreeNode* root){
      if(root == nullptr) return;
      dep++;
      if(root->left == nullptr && root->right == nullptr)
        if(maxDep < dep) maxDep = dep;
      getD(root->left);
      getD(root->right);
      dep--;

    }
};

int main(){


  return 0;
}