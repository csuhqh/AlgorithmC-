/**
 * https://leetcode.cn/problems/house-robber-iii/
 */
#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 必须后序便利
*/
class Solution {
public:
    
    int rob(TreeNode *root) {
      auto result = robTree(root); 
      return max(result.first, result.second);
    }
    //获取该子树的最大收益(不偷，偷)
    pair<int, int> robTree(TreeNode* cur){
      if(cur == NULL) return make_pair<int, int>(0, 0);
      auto left = robTree(cur->left);
      auto right = robTree(cur->right);
      //偷cur， 不偷左右孩子
      int val1 = cur->val + left.first + right.first;
      //不偷cur
      int val2 = max(left.first, left.second) + max(right.first, right.second);
      return make_pair(val2, val1);
    }
};

int main() {
    return 0;
}