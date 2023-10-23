/**
 * https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/
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
  /**
   * 主要是每一轮要确定根节点。每一轮要确定左子树和右字树的便利序列
  */
public:
    TreeNode* traversal(vector<int>& inorder, int inorderBegin, int inorderEnd, vector<int>& postorder, int postorderBegin, int postorderEnd){
      if(inorderBegin > inorderEnd) return nullptr;
      //确定根节点
      TreeNode* root = new TreeNode(postorder[postorderEnd]);
      if(inorderBegin == inorderEnd) return root; //只有一个根节点
      //确定切割点
      int inorderSplitIndex; //中序序列的切割点
      for(inorderSplitIndex=inorderBegin; inorderSplitIndex < inorderEnd; ++inorderSplitIndex){
        if(inorder[inorderSplitIndex] == root->val) break;
      }
      int postSplitIndex = postorderBegin + (inorderSplitIndex - inorderBegin) - 1; //后序的切割点
      // cout << inorderSplitIndex << " " << postSplitIndex;
      //左子树
      root->left = traversal(inorder, inorderBegin, inorderSplitIndex - 1, postorder, postorderBegin, postSplitIndex);
      //右子树
      root->right = traversal(inorder, inorderSplitIndex + 1, inorderEnd, postorder, postSplitIndex + 1, postorderEnd - 1);
      return root;
    }


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
      if(inorder.size() == 0) return nullptr;
      return traversal(inorder, 0, inorder.size() - 1, postorder, 0, postorder.size() - 1);
    }
};

