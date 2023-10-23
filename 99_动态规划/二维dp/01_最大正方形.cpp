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

//动态规划
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        int maxArea = 0;
        //dp[i][j]为以i, j 为左上角的最大正方形的面积
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //dp[x][n - 1]
        for(int i = 0; i < m; ++i){
            dp[i][n - 1] = matrix[i][n - 1] == '1'? 1 : 0;
            maxArea = max(maxArea, dp[i][n - 1]);
        }
        //dp[m - 1][x]
        for(int i = 0; i < n; ++i){
            dp[m - 1][i] = matrix[m - 1][i] == '1' ? 1 : 0;
            maxArea = max(maxArea, dp[m - 1][i]);
        }
        //单独处理交汇处
        if(matrix[m - 1][n - 1] == '0') dp[m - 1][n - 1] = 0; 
        else dp[m - 1][n - 1] = 1;

        for(int i = m - 2; i >= 0; --i){
            for(int j = n - 2; j >= 0; --j){
                if(matrix[i][j] == '0'){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = min({dp[i + 1][j], dp[i + 1][j + 1], dp[i][j + 1]}) + 1;
                maxArea = max(dp[i][j], maxArea);
            }
        }

        return maxArea * maxArea;
    }
};