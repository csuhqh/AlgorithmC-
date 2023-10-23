/**
 * https://leetcode.cn/problems/find-mode-in-binary-search-tree/
*/

#include <bits/stdc++.h>
using namespace std;
/**
 * 二叉搜索树的中序变量是一个递增序列
*/

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
    vector<int> result;
    multimap<int, int> kv;
    TreeNode* pre = nullptr;
    int count = 0;
    int maxCount = 0; //用于判断count是否更新
    vector<int> findMode(TreeNode* root) {
      traver(root);
      return result;
    }

    void traver(TreeNode* root){
      if(root == nullptr) return;
      traver(root->left);
      if(pre && pre->val == root->val) count++;
      else {
        count = 1;
      }
      pre = root;
      if(count == maxCount){
        result.push_back(root->val);
      }
      if(count > maxCount){
          maxCount = count;
          result.clear();
          result.push_back(root->val);
      }


      traver(root->right);
    }
};