/**
 * https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<char>> phones;
    int dep;
    string path;
    vector<string> result;

    vector<string> letterCombinations(string digits) {
      if(digits.size() == 0) return {};
      //构建电话本
      char s = 'a';
      for(int i = 0; i < 5; ++i){
        vector<char> temp;
        for(int j = 0; j < 3; ++j){
          temp.push_back(s);
          s++;
        }
        phones.push_back(temp);
        
        temp.clear();
      }
      phones.push_back({'p', 'q', 'r', 's'});
      phones.push_back({'t', 'u', 'v'});
      phones.push_back({'w', 'x', 'y', 'z'});
      
      //回溯
      backtracking(digits, 0);
      return result;

    }
    void backtracking(string& digits, int start){
      if(dep == digits.size()){ //路径长度
        result.push_back(path);
        return;
      }
      vector<char> word = phones[digits[start] - '2'];
      cout << word[0] << endl;
      for(int i = 0; i < word.size(); ++i){
        dep++;
        path.push_back(word[i]);
        backtracking(digits, start + 1); //进入下一个节点
        dep--;
        path.pop_back();

      }

    }
};
