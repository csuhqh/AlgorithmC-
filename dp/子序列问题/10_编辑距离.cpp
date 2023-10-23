/*
https://leetcode.cn/problems/edit-distance/
*/

#include "bits/stdc++.h"
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0));
        for(int i = 0; i <= word1.size(); ++i) dp[i][0] = i;
        for(int i = 0; i <= word2.size(); ++i) dp[0][i] = i;

        for(int i = 1; i <= word1.size(); ++i){
            for(int j = 1; j <= word2.size(); ++j){
                if(word1[i - 1] == word2[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }else{
                    //在两个单词不相同时，dp[i - 1][j - 1] + 2 ==> dp[i - 1][j - 1] + 1只需要其他操作就可以克服，比如修改
                    dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};


int main(){
    string word1 = "horse", word2 = "ros";
    Solution solu;
    int res = solu.minDistance(word1, word2);
    cout << res << endl;

    return 0;
}