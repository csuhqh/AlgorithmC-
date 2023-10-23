/**
 * https://leetcode.cn/problems/number-of-islands/description/
*/
#include <bits/stdc++.h>
using namespace std;
/**
 * 记得visited时&。
 * 求联通分量
*/

class Solution {
public:
    int dir[4][2] = {0, 1, 1, 0, -1, 0, 0, -1};
    int m, n;
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y){
        queue<pair<int, int>> que;
        que.push(make_pair(x, y));
        visited[x][y] = true;
        while(!que.empty()){
            auto node = que.front();
            // visited[node.first][node.second] = true;
            que.pop();
            for(int i = 0; i < 4; ++i){
                int newX = node.first + dir[i][0];
                int newY = node.second + dir[i][1];
                if(newX < 0 || newY < 0 || newX >= m || newY >= n) continue;
                if(grid[newX][newY] == '0' || visited[newX][newY]) continue;
                que.push(make_pair(newX, newY));
                visited[newX][newY] = true;
            }

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        this->m = grid.size(), this->n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        int count = 0;
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(!visited[i][j] && grid[i][j] == '1'){ 
                    count++;
                    bfs(grid, visited,i, j);
                }
            }

        }
        return count;
    }
};