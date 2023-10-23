/**
 * https://leetcode.cn/problems/palindromic-substrings/
*/

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), false));
        int res = 0;
        for(int i = s.size() - 1; i >= 0; --i){
            for(int j = i; j < s.size(); ++j){
                if(s[i] == s[j]){
                    if(j - i <= 1){
                        res++;
                        dp[i][j] = true;
                    }else if(dp[i + 1][j - 1]){
                        res++;
                        dp[i][j] = true;
                    }
                }
            }
        }
        return res;
    }
};



int main(){
    string s = "abc";
    Solution solu;
    int res = solu.countSubstrings(s);
    cout << res << endl;
    return 0;
}