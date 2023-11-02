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


class Solution {
public:
    int k;
    vector<int> path;
    vector<vector<int>> res;
    void dfs(int n, int val){
        //处理当前节点
        path.push_back(val);
        if(path.size() == k){
            res.push_back(path);
            return;
        }
        for(int i = val + 1; i <= n; ++i){
            dfs(n, i);
            path.pop_back(); //回溯
        }
    }

    vector<vector<int>> combine(int n, int k) {
        this->k = k;
        for(int i = 1; i <= n; ++i){
            dfs(n, i);
            path.pop_back(); //记得回溯
        }
        return res;
    }
};



