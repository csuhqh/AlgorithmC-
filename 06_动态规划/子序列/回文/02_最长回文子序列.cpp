/**
 * https://leetcode.cn/problems/longest-palindromic-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s) {
      //dp[i][j] 从s[i:j]范围内的回文子序列长度
      vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));
      for(int i = 0; i < s.size(); ++i) dp[i][i] = 1;

      for(int i = 1; i < s.size(); ++i){
        for(int j = i - 1; j >= 0; --j){
          if(s[i] == s[j]){
            dp[j][i] = dp[j + 1][i - 1] + 2;
          }else{
            dp[j][i] = max(dp[j][i - 1], dp[j + 1][i]);
          }
        }
      }
      return dp[0][s.size() -1];
    }
};

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        //dp[i][j] 表示i, j区间中最长子序列长度(删减问题)
        //dp[i][j] = dp[i + 1][j - 1] + 2 or dp[i + 1][j] or dp[i][j - 1]
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));
        for(int i = 0; i < s.size(); ++i){
            dp[i][i] = 1;
        }
        for(int j = 0; j < s.size(); ++j){
            for(int i = j - 1; i >= 0; --i){
        
                if(s[i] == s[j]){
                    if(j - i == 1){ //加了合理些
                        dp[i][j] = 2;
                        continue;
                    }
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                }else{
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[0][s.size() - 1];
    }
};