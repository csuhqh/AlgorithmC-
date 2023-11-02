/**
 * https://leetcode.cn/problems/balanced-binary-tree/
*/
#include <bits/stdc++.h>
#include <cmath>
using namespace std;


class Solution {
public:
    int dep;
    int maxDep;
    void getD(TreeNode* root){
        if(root == nullptr) return;
        dep++;
        if(root->left == nullptr && root->right == nullptr) maxDep = max(dep, maxDep);
        getD(root->left);
        getD(root->right);
        dep--;
    }

    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        maxDep = 0, dep = 0;
        getD(root->left);
        int lh = maxDep;
        maxDep = 0, dep = 0;
        getD(root->right);
        int rh = maxDep;
        bool isBalance = abs(rh - lh) <= 1;

        return isBalance && isBalanced(root->left) && isBalanced(root->right);

    }
};