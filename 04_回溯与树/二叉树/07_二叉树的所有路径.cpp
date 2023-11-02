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
    vector<string> res;
    vector<int> path;
    void dfs(TreeNode* root){
        if(root == nullptr) return;

        path.push_back(root->val);

        if(root->left == nullptr && root->right == nullptr){
            string s;
            s.append(to_string(path[0]));
            for(int i = 1; i < path.size(); ++i){
                s.append("->");
                s.append(to_string(path[i]));
            }
            res.push_back(s);
        }
        dfs(root->left);
        dfs(root->right);
        path.pop_back();

    }

    vector<string> binaryTreePaths(TreeNode* root) {
        res.clear();
        path.clear();
        dfs(root);
        return res;
    }
};