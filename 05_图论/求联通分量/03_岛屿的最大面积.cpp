/**
 * https://leetcode.cn/problems/max-area-of-island/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};
    int m, n;
    int maxArea{0};
    int area = 0;
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int x, int y){
        if(grid[x][y] == 0 || visited[x][y]) return;
        visited[x][y] = true;
        area++;
        for(int i = 0; i < 4; ++i){
            int newX = x + dir[i][0];
            int newY = y + dir[i][1];
            if(newX < 0 || newY < 0 || newX >= m || newY >= n) continue;
            if(visited[newX][newY] || grid[newX][newY] == 0) continue;
            dfs(grid, visited, newX, newY);
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1 && !visited[i][j]){ //可抵达 且 未访问过
                    area = 0;
                    dfs(grid, visited, i, j);
                    maxArea = max(area, maxArea);
                }
            }
        }
        return maxArea;
    }
};