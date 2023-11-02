/**
题目: 从第一列到最后一列，所经过的1的最小数量。
输入:
4 4
1 1 1 0
1 1 1 0
0 0 1 0
0 1 1 1
输出:
6
*/
#include <bits/stdc++.h>
using namespace std;

class Solution{
  
}

// class Solution{
//   int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
//   int m{0};
//   int n{0};
//   public:
//     int solu(vector<vector<int>> &matrix, int m, int n){
//       this->m =  m, this->n = n;
//       int result = 0x3f3f3f3f;
//       for(int j = 0; j < m; ++j){
//         if(matrix[j][0] == 1){
//           int ret = bfs(matrix, j, 0);
//           if(ret == 0) continue;
//           result = min(ret, result);
//         }
          
//       }

//       return result;
//     }
//     //正确答案
//     int bfs(vector<vector<int>> &matrix, int x, int y){
//       queue<pair<int, int>> q;
//       vector<vector<bool>> visited(m, vector<bool>(n, false));
//       q.push(make_pair(x, y)); //节点入栈
//       visited[x][y] = true;
//       int path = 0;
//       while(!q.empty()){
//         int size = q.size();
//         path++; //到达下一层
//         for(int i = 0; i < size; ++i){ //注意这里
//           auto cur = q.front();
//           //对节点进行处理
//           q.pop();
//           if(matrix[cur.first][cur.second] == 1 && cur.second == n - 1) return path;
//           //继续bfs
//           for(int i = 0; i < 4; ++i){
//             int newX = cur.first + dir[i][0];
//             int newY = cur.second + dir[i][1];
//             if(newX < 0 || newY < 0 || newX >= m || newY >= n) continue;
//             if(matrix[newX][newY] == 0 || visited[newX][newY]) continue;
//             q.push(make_pair(newX, newY));
//             visited[newX][newY] = true;
//           }
//         }


//       }
//       return path;
//     }
// };



int main(){
  int m, n;
  cin >> m >> n;
  vector<vector<int>> matrix;
  for(int i = 0; i < m; ++i){
    vector<int> temp(n);
    for(int j = 0; j < n; ++j){
      cin >> temp[j];
    }
    matrix.push_back(temp);
    temp.clear();
  }
  Solution solu;
  int res = solu.solu(matrix, m, n);
  cout << res << endl;


}