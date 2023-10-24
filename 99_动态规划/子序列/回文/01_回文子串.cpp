/**
 * https://leetcode.cn/problems/palindromic-substrings/
*/
#include <bits/stdc++.h>
using namespace std;
/**
 * 判断一个字符串中有多少个回文子串
*/
class Solution {
public:
    int countSubstrings(string s) {
      //dp[i][j] ==> 表示s[i]~s[j]是否为回文子串
      vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
      for(int i = 0; i < s.size(); ++i) dp[i][i] = true;

      for(int i = 1; i < s.size(); ++i){
        for(int j = i - 1; j >= 0; --j){
          if(s[j] == s[i]){
            if(j + 1 == i || dp[j + 1][i - 1]) dp[j][i] = true; //相邻情况与子序列是回文
          }
        }
      }
      //统计
      int result = 0;
      for(int i = 0; i < s.size(); ++i){
        for(int j = 0; j < s.size(); ++j){
          if(dp[i][j]) result++; 
        }

      }
      return result;
    }
};

//优化
class Solution {
public:
    int countSubstrings(string s) {
        //dp[i][j] = dp[i + 1][j - 1]
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        int res = 0;
        for(int i = 0; i < s.size(); ++i){
            for(int j = i; j >= 0; --j){
                if(s[i] == s[j]){
                    if(i - j <= 1 || dp[j + 1][i - 1]){ //i - j <= 1，说明ij长度为1或2都是回文子串。
                        dp[j][i] = true;
                        res++;
                    }
                }else{
                    dp[j][i] = false;
                }
                
            }
        }
        return res;
    }

};

//
class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size()));

        //dp[i][j] = dp[i + 1][j - 1] && s[i]== s[j]
        int res = s.size();
        for(int i = 0; i < s.size();++i){
            dp[i][i] = 1;
        }
        // for(int i = s.size() - 1; i >= 0; --i){
        //     for(int j = i - 1; j >= 0; --j){
        //         cout << "(" << i << j << endl;
        //         if(s[i] == s[j]){
        //             if(i - j == 1 || dp[j + 1][i - 1]){
        //                 dp[j][i] = 1;
        //                 cout << "i - j" << i - j << " == "<< i << " " << j<< " " <<endl;
        //                 res++;
        //             }else{
        //                 dp[j][i] = 0;
        //             }
        //         }else{
        //             dp[j][i] = 0;
        //         }
        //     }
        // }
        for(int j = 0; j < s.size(); ++j){
            for(int i = j - 1; i >= 0; --i){
                if(s[i] == s[j]){
                    if(j - i == 1 || dp[i + 1][j - 1]){
                        res++;
                        dp[i][j] = 1;
                    }
                }
            }
        }
        return res;
    }
};