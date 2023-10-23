/**
 * https://leetcode.cn/problems/validate-binary-search-tree/
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
    TreeNode* pre = nullptr;
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        bool leftFlag = isValidBST(root->left); //root为最左节点
        //保证根节点>左子树
        if(pre && pre->val >= root->val) return false;
        pre = root;
        bool rightFlag = isValidBST(root->right);
        return leftFlag && rightFlag;
    }
};
