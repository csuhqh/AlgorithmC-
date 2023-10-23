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
    int count = 0;
    int countNodes(TreeNode* root) {
      getCount(root);
      return count;
    }
    void getCount(TreeNode* root){
      if(root == nullptr) return;
      count++;
      getCount(root->left);
      getCount(root->right);
    }
};

int main(){


  return 0;
}