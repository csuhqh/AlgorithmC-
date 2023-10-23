/*
 * https://leetcode.cn/problems/is-subsequence/
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //非dp
    // bool isSubsequence(string s, string t) {
    //     if(s == "") return true;
    //     int count = 0;
    //     for(int i = 0; i < t.length(); ++i){
    //         if(t[i] == s[count]){
    //             count += 1;
    //         }
    //         if(count == s.length()){
    //             return true;
    //         }

    //     }
    //     return false;
    // }
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));
        for(int i = 1; i <= s.length(); ++i){
            for(int j = 1; j <= t.length(); ++j){
                if(s[i - 1] == t[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }else{
                    dp[i][j] = dp[i][j - 1];
                }
            }
           
        }
        return dp[s.size()][t.size()] == s.length();
    }
};


int main(){
    string s = "b", t = "c";
    Solution solu;
    bool res = solu.isSubsequence(s, t);
    cout << res << endl;
    return 0;
}