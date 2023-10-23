/***
 * https://leetcode.cn/problems/combinations/
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * target为值用dp，target为个数用回溯
*/

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    int dep = 0; //当前深度
    int k = 0; //到达某一层返回
    vector<vector<int>> combine(int n, int k) {
      this->k = k;
      backtracking(n, 1);
      return result;
    }

    void backtracking(int n, int start){
      if(dep == k){
        result.push_back(path);
        return;
      }
      for(int i = start; i <= (n - (k - dep) + 1 ); ++i){ //n剪枝(n - (k - dep) + 1
        dep++; //深度+在这
        path.push_back(i);
        backtracking(n, i + 1);
        dep--;
        path.pop_back();
      }
    }
};




