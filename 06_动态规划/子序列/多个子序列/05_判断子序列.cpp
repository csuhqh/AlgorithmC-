/**
 * https://leetcode.cn/problems/is-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 思路1: 双指针（秒过）
 * 思路2: 两个字符串的公共最长子序列 == 大小是否等于。
*/
class Solution {
public:
    //双指针很简单, 但是请用dp求解
    bool isSubsequence(string s, string t) {
      //dp[i][j] 长度为i 和 长度为j 的公共子序列
      vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0)); 
      dp[0][0] = 0;
      for(int i = 1; i <= s.size(); ++i){
        for(int j = 1; j <= s.size(); ++j){
          if(s[i - 1] == t[j - 1]){
            dp[i][j] = dp[i - 1][j - 1] + 1;
          }else{
            dp[i][j] = dp[i][j - 1]; //???
          }
        }
      }
      if(dp[s.size()][t.size()] == s.size()) return true;
      return false;
    }
    
};

int main(){
  return 0;
}
