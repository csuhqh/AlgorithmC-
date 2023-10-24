/**
 * https://leetcode.cn/problems/maximal-square/description/?envType=study-plan-v2&envId=top-interview-150
*/
#include <bits/stdc++.h>
using namespace std;
//暴力 （75/78）
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxArea = 0; 
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                int edge = n;
                for(int a = i; a < m; ++a){
                    for(int b = j; b < edge; ++b){
                        if(matrix[a][b] != '1'){
                            edge = b;
                            break;
                        }
                    }
                    int len = min(edge - j, a - i + 1);
                    maxArea = max(len * len, maxArea);
                }

            }
        }
        return maxArea;
    }
};

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        int edge = 0;
        //初始化二维
        for(int i = 0; i < m; ++i){
            dp[i][n - 1] = matrix[i][n - 1] - '0';
            if(dp[i][n - 1] == 1) edge = 1;
        };
        for(int j = 0; j < n; ++j){
            dp[m - 1][j] = matrix[m - 1][j] - '0';
            if(dp[m - 1][j] == 1) edge = 1;
        };
        //二维，此处交汇处不管。
        //
        for(int i = m - 2; i >= 0; --i){
            for(int j = n - 2; j >= 0; --j){
                if(matrix[i][j] == '1'){
                    dp[i][j] = min({dp[i + 1][j + 1], dp[i + 1][j], dp[i][j + 1]}) + 1;
                }
                edge = max(edge, dp[i][j]);
            }
        }
        return edge * edge;
    }
};