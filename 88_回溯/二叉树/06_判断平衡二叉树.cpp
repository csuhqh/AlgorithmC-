/**
 * https://leetcode.cn/problems/balanced-binary-tree/
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
    int n{0};
    int maxH{0};
    bool isBalanced(TreeNode* root) {
      //判断根是否平衡
      if(root == nullptr) return true;
      //获取左字数高度
      n = 0, maxH = 0;
      getH(root->left);
      int leftH = maxH;

      n = 0, maxH = 0;
      getH(root->right);
      int rightH = maxH;
      cout << "left" << leftH << "right: " << rightH << endl;
      return abs(leftH - rightH) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }

    void getH(TreeNode* root){
      if(root == nullptr) return;
      n++;
      if(!root->left && !root->right){
        if(maxH <= n) maxH = n;
      }
      getH(root->left);
      getH(root->right);
      n--;
    }

    
};

int main(){


  return 0;
}