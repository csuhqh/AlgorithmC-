/**
 * https://leetcode.cn/problems/number-of-islands/
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
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1}; //四个方向
    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){ 
      if(visited[x][y] == true || grid[x][y] == '0') return;
      visited[x][y] = true;
      for(int i = 0; i < 4; ++i){
        int newX = x + dir[i][0];
        int newY = y + dir[i][1];
        if(newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size()) continue;
        dfs(grid, visited, newX, newY);
      }

    }

    int numIslands(vector<vector<char>>& grid) {
        int result = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i = 0; i < n; ++i){
          for(int j = 0; j < m; ++j){
            if(!visited[i][j] && grid[i][j] == '1'){
              result++; //发现新岛屿
              dfs(grid, visited, i, j);
            }
          }
        }
        return result;
    }
};

