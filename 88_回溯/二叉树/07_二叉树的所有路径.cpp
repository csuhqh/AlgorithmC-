/**
 * https://leetcode.cn/problems/binary-tree-paths/
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
    vector<string> result;
    vector<int> path;
    vector<string> binaryTreePaths(TreeNode* root) {
      traverse(root);
      return result;
    }

    void traverse(TreeNode*& root){
      if(root == nullptr) return;
      path.push_back(root->val);
      if(!root->right && !root->left){//yezi
        string ap;
        ap = to_string(path[0]);
        for(int i = 1; i < path.size(); ++i){
          ap += "->" + to_string(path[i]);
        }
        result.push_back(ap);
      }
      traverse(root->left);
      traverse(root->right);
      path.pop_back();
    }
};
 