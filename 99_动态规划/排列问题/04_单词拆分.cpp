/**
 * https://leetcode.cn/problems/word-break/
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
      vector<bool> dp(s.length() + 1, false);
      dp[0] = true;
      for(int i = 1; i <= s.size(); ++i){
        for(int j = 0; j < wordDict.size(); ++j){
          string word = wordDict[j];
          if(i >= word.length()){
            if(s.substr(i - word.length(), word.length()) == word){ //注意还要验证单词是否相等。
              dp[i] = dp[i - word.length()] && true;
              if(dp[i]) break; //关键，我们只在乎dp[i]能不能组合成功， 既然知道为true就直接返回
            }
          }
        }
      }
      for(auto i : dp){
        cout << i << endl;
      }
      return dp[s.length()];

    }
};