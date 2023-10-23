/**
 * https://leetcode.cn/problems/symmetric-tree/
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
    bool isSymmetric(TreeNode* root) {
      if(root == nullptr) return true;
      return compare(root->left, root->right);
    }
    bool compare(TreeNode* left, TreeNode* right){
      if(left == nullptr && right == nullptr) return true; //退出条件
      else if(left && !right) return false;
      else if(!left && right) return false;
      else if(left->val != right->val) return false;
      else return compare(left->left, right->right) && compare(left->right, right->left);
    }
};



TreeNode* buildTree(vector<int>& nums, int start) {
    if (nums[start] == '#' || nums.size() <= start)
        return nullptr;
    TreeNode* root = new TreeNode(nums[start]);
    root->left = buildTree(nums, start * 2 + 1);
    root->right = buildTree(nums, start * 2 + 2);
    return root;
}
void printTree(TreeNode*& root) {
    if (root) {
        cout << root->val << " ";
        printTree(root->left);
        printTree(root->right);
    }
}

int main() {
    vector<int> nums = {1,2,2,3,4,4,3};
    Solution solu;
    TreeNode* root = buildTree(nums, 0);
    bool result = solu.isSymmetric(root);
    cout << result << endl;
    return 0;
}