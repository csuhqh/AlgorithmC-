/**
 * https://leetcode.cn/problems/spiral-matrix-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));
        int i = 0, j = 0;
        int i_bot = n - 1, i_top = 0, j_rig = n - 1, j_left = 0;
        int round = 1;
        int k = 1;
        while(k <= n * n){
            if(round % 4 == 1){ //i不变, j变大
                while(k <= n*n && j <= j_rig){
                    matrix[i][j] = k;
                    ++j;
                    ++k;
                }
                i_top += 1;
                j -= 1;
                i += 1;
            }else if(round % 4 == 2){
                while(k <= n * n && i <= i_bot){
                    matrix[i][j] = k;
                    ++i;
                    ++k;
                }
                j_rig -= 1;
                i -= 1;
                j -= 1;
            }else if(round % 4 == 3){
                while(k <= n*n && j >= j_left){
                    matrix[i][j] = k;
                    --j;
                    ++k;
                }
                i_bot -= 1;
                j += 1;
                i -= 1;
            }else if(round % 4 == 0){
                while(k <= n * n && i >= i_top){
                    matrix[i][j] = k;
                    --i;
                    ++k;

                }
                j_left += 1;
                i += 1;
                j += 1;
            }
            round += 1;
            cout << k << endl;
        }
        return matrix;
    }
    
};


int main(){
    int n = 3;
    Solution solu;
    vector<vector<int>> matrix = solu.generateMatrix(n);


    //打印列表
    cout << "[";
    for(int i = 0; i < matrix.size(); ++i){
        vector<int> temp = matrix[i];
        cout << "[";
        for(int j = 0; j < temp.size(); ++j){
            cout << temp[j];
            if(j != temp.size() - 1) cout << ", ";
        }
        cout << "]";
        if(i != matrix.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
    return 0;
}