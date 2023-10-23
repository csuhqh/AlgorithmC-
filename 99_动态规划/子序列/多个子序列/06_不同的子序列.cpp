/**
 * https://leetcode.cn/problems/distinct-subsequences/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
      //dp[i][j] 长度为i的字符串的子序列在长度为j的字符串中出现的个数
      vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1));
      for(int i = 0; i <= s.size(); ++i) dp[0][i] = 1; //这里时关键
      for(int i = 0; i <= t.size(); ++i) dp[i][0] = 0;
      for(int i = 1; i <= s.size(); ++i){
        for(int j = 1; j <= t.size(); ++j){
          if(s[i - 1] == t[j - 1]){
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
          }else{
            dp[i][j] = dp[i - 1][j];
          }
        }
      }

    }
};

//
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<uint64_t>> dp(s.size() + 1, vector<uint64_t>(t.size() + 1, 0));
        for(int i = 0; i < t.size(); ++i) dp[0][i] = 1;
        for(int i = 1; i < s.size(); ++i) dp[i][0] = 0; //注意这里
        dp[0][0] = 0;
        for(int i = 1; i <= s.size(); ++i){
            for(int j = 1; j <= t.size(); ++j){
                if(s[i] == t[j]){
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }else{
                    dp[i][j] = dp[i - 1][j]; 
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};