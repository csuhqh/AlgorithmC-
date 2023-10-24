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
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
      queue<pair<int, int>> que;
      que.push({x, y});
      visited[x][y] = true;
      while(!que.empty()){
        pair<int, int> cur = que.front();
        que.pop();
        int curx = cur.first;
        int cury = cur.second;
        for(int i = 0; i < 4; ++i){
          int newX = curx + dir[i][0];
          int newY = cury + dir[i][1];
          if(newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size()) continue;
          if(!visited[newX][newY] && grid[newX][newY] == '1'){ //加入队列
            que.push({newX, newY});
            visited[newX][newY] = true; 
          }
        }
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
              bfs(grid, visited, i, j);
            }
          }
        }
        return result;
    }
};