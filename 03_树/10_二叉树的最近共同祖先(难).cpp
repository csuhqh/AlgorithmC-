/**
 * https://leetcode.cn/problems/lowest-common-ancestor-of-a-binary-tree/
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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) {
            return nullptr;  // 如果树为空，返回空指针
        }

        if (root == p || root == q) {
            return root;  // 如果当前节点等于 p 或 q，那么它就是最近公共祖先
        }

        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);

        if (left && right) {
            return root;  // 如果左子树和右子树都找到了 p 和 q，那么当前节点就是最近公共祖先
        } else if (left) {
            return left;  // 如果只在左子树中找到了 p 或 q，那么左子树中的先节点就是最近公共祖先
        } else {
            return right;  // 如果只在右子树中找到了 p 或 q，那么右子树中的节点就是最近公共祖先
        }
    }
};
