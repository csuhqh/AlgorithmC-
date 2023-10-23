/**
 * https://leetcode.cn/problems/surrounded-regions/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int direct[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
    int m, n;
    vector<pair<int, int>> begirt; //被包围的区域
    bool isBegirt{true}; //是否被包围
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int x, int y){
      if(board[x][y] == 'X' || visited[x][y]) return;
      visited[x][y] = true;
      begirt.push_back({x, y});
      for(int i = 0; i < 4; ++i){
        int newX = x + direct[i][0];
        int newY = y + direct[i][1];
        if(newX < 0 || newY < 0 || newX >= m || newY >= n){
          isBegirt = false;
          continue;
        }
        dfs(board, visited, newX, newY);
      }
    }

    void solve(vector<vector<char>>& board) {
      m = board.size(), n = board[0].size();
      vector<vector<bool>> visited(m, vector<bool>(n, false));
      for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
          isBegirt = true;
          begirt.clear();
          dfs(board, visited, i, j);
          if(isBegirt){
            for(auto it: begirt){
              board[it.first][it.second] = 'X';
            }
          }
        }
      }
    }
};