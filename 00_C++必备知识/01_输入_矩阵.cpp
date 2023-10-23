/**
 * 输入矩阵
输入:
4 4
1 1 1 0
1 1 1 0
0 0 1 0
0 1 1 1
*/
#include <bits/stdc++.h>
using namespace std;


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

}
