#include <bits/stdc++.h>
using namespace std;
/**
 * https://leetcode.cn/problems/invert-binary-tree/submissions/
 * 二叉树的翻转 
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *invertTree(TreeNode*& root) {
      if(root == nullptr) return root;
      TreeNode* temp;
      temp = root->left;
      root->left = root->right;
      root->right = temp;
      invertTree(root->left);
      invertTree(root->right);
      return root;
    }
};

TreeNode* buildTree(vector<int>& nums, int start){
    if(nums[start] == '#' || nums.size() <= start) return nullptr;
    TreeNode* root = new TreeNode(nums[start]);
    root->left = buildTree(nums, start * 2 + 1);
    root->right = buildTree(nums, start* 2 + 2);
    return root;
}
void printTree(TreeNode*& root){
  
  if(root){
    cout << root->val << " ";
    printTree(root->left);
    printTree(root->right);
  }

}

int main() {
    vector<int> nums = {4,2,7,1,3,6,9};
    TreeNode* root = buildTree(nums, 0);
    Solution solu;
    TreeNode* result = solu.invertTree(root);
    cout << "Tree: ";
    printTree(result);
    cout << endl;
    return 0;
}