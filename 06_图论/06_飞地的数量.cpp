/**
 * https://leetcode.cn/problems/number-of-enclaves/description/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int direct[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    bool reachable = false;
    int count = 0;
    int m, n;
    int result{0};
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
      if(visited[x][y] || grid[x][y] == 0) return;
      visited[x][y] = true;
      count++;
      for(int i = 0; i < 4; ++i){
        int newX = x + direct[i][0];
        int newY = y + direct[i][1];
        if(newX < 0 || newY < 0 || newX >= m || newY >= n){
          reachable = true;
          continue;
        }
        dfs(grid, visited, newX, newY);
      }
    }

    int numEnclaves(vector<vector<int>>& grid) {
      m = grid.size(), n = grid[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
          reachable = false;
          count = 0;
          dfs(grid, visited, i, j); //每一趟会把都是1的部分染色
          if(!reachable) result += count;
        }
      }
      return result;
    }
};
