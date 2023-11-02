#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int direct[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};  //上下左右
    int maxArea = 0;
    int area = 0;
    int m, n;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
      if(visited[x][y] || grid[x][y] == 0) return; //自动排除访问过的点 （有哪些退出条件，用||表示）
      visited[x][y] = true;
      area += 1;
      if(area > maxArea) maxArea = area;
      for(int i = 0; i < 4; ++i){
        int newX = x + direct[i][0];
        int newY = y + direct[i][1];
        if(newX < 0 || newY < 0 || newX >= m || newY >= n) continue;  //这个不能忘记
        dfs(grid, visited, newX, newY);
      }
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
      m = grid.size(), n = grid[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            area = 0;
            dfs(grid, visited, i, j);
        }
      }
      return maxArea;
    }
};

int mian(){

}