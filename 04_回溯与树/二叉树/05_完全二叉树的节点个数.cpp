#include <bits/stdc++.h>
using namespace std;

/**
 * https://leetcode.cn/problems/count-complete-tree-nodes/
*/
class Solution {
public:

    int count{0};
    void dfs(TreeNode*& root){
        if(!root) return;
        count++;
        dfs(root->left);
        dfs(root->right);
    }

    int countNodes(TreeNode* root) {
        dfs(root);
        return count;
    }
};

