/**
 * https://leetcode.cn/problems/number-of-enclaves/description/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int m, n;
    int count{0};
    int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    bool isCanFlay{false};
    void dfs(vector<vector<int>>& grid, vector<vector<bool>> &visited,int x, int y){
      if(grid[x][y] == 0 || visited[x][y]) return;

      //对节点的处理放这！！！！
      visited[x][y] = true;
      count++;
      if(x == m - 1 || y == n - 1 || x == 0 || y == 0) isCanFlay = true;


      for(int i = 0; i < 4; ++i){
        int newX = x + dir[i][0];
        int newY = y + dir[i][1];
        if(newX < 0 || newY < 0 || newX >= m || newY >= n) continue;
        if(grid[newX][newY] == 0 || visited[newX][newY]) continue;
        dfs(grid, visited, newX, newY);
      }
    }

    int numEnclaves(vector<vector<int>>& grid) {
      m = grid.size(), n = grid[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      int result = 0;
      for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
          if(grid[i][j] == 1 && !visited[i][j]){
            isCanFlay = false;
            count = 0;
            dfs(grid, visited, i, j);
            if(!isCanFlay) result += count;
          }
        }
      }
      return result;

    }
};