/*
https://leetcode.cn/problems/distinct-subsequences/
*/

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<u_int64_t>> dp(s.length() + 1, vector<u_int64_t>(t.length() + 1, 0));
        for(int i = 0; i <= s.length(); ++i) dp[i][0] = 1;

        for(int i = 1; i <= s.length(); ++i){
            for(int j = 1; j <= t.length(); ++j){ //遍历不同长度的j
                if(s[i - 1] == t[j - 1]){ //相同情况
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }else{ //不同情况，回朔
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};


int main(){
    string s = "rabbbit", t = "rabbit";
    Solution solu;
    int res = solu.numDistinct(s, t);
    cout << res << endl;

    return 0;
}