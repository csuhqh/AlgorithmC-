/**
 * https://leetcode.cn/problems/convert-bst-to-greater-tree/
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
    int pre = 0;
    void traversal(TreeNode* cur){
      if(cur == nullptr) return;
      traversal(cur->right); //找到最右
      cur->val += pre;
      pre = cur->val;
      traversal(cur->left);
    }

    TreeNode* convertBST(TreeNode* root) {
      traversal(root);
      return root;
    }
};



int main(){


  return 0;
}
