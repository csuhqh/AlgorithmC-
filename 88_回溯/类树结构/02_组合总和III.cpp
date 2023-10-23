/**
 * https://leetcode.cn/problems/combination-sum-iii/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    int sum = 0;
    int dep{0};
    int k;
    int n;
    vector<vector<int>> combinationSum3(int k, int n) {
      this->k = k;
      this->n = n;
      backtracking(1);
      return result;
    }

    void backtracking(int start){
      if(dep == k){
        if(sum == n) result.push_back(path);
        return; //指定长度要return
      }
      for(int i = start; i <= 9; ++i){
        dep++;
        sum += i;
        path.push_back(i);
        backtracking(i + 1);
        sum -= i;
        path.pop_back();
        dep--;
      }

    }
};