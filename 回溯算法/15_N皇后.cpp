/**
 * url:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<string>> solveNQueens(int n) {
            // vector<string> chessboard(n, string(n, '.'));
            vector<string> chessboard(n, string(n, '.')); // string(n, ".") 表示n个.相加
            backtracking(chessboard, n, 0);
            return result;
        }
    private:
        vector<vector<string>> result;
        vector<string> path;
        void backtracking(vector<string>& chessboard, int n, int row){
            if(row == n){
                result.push_back(chessboard); //加入叶子节点
                return;
            }
            for(int col = 0; col < n; col++){
                if(isValid(chessboard, n, row, col)){ //放置一颗
                    chessboard[row][col] = 'Q'; //放置皇后
                    backtracking(chessboard, n, row + 1);
                    chessboard[row][col] = '.'; //回溯
                }
            }

        } 
        bool isValid(vector<string>& chessboard, int n, int row, int col){
            //检查列
            for(int i = 0; i < row; ++i){
                if(chessboard[i][col] == 'Q') return false;
            }
            //检查135度
            for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j){
                if(chessboard[i][j] == 'Q') return false;
            }
            //检查135度
            for(int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j){
                if(chessboard[i][j] == 'Q') return false;
            }
            return true;
        }
};


int main(){
    //输入数据: 数值输入
    // int a, b;
    // cin >> a >> b;
    // cout << "输入:" << a << " " << b << endl;
    //字符串输入
    // string s, e;
    // cin >> s >> e;
    // cout << "输入:" << s << " " << e <<  endl;
    //读取一行字符串（遇到回车）
    // string f;
    // cin.get();
    // getline(cin, f);
    // cout << "输入:" << f << endl;
    //逐个字符读取，可以读取任意字符(包括换行和回车) cin.get() 
    // int num;
    // while(cin >> num){
    //     if(cin.get() == '\n'){
    //         cout << num << endl;
    //     }
    // }
    //手工输入
    int n = 4;
    Solution solu;
    vector<vector<string>> result = solu.solveNQueens(n);

    cout << "result: ";

    //打印普通
    // cout << result << endl;
    //打印vector
    // for(int i = 0; i < result.size(); ++i){
    //     cout << result[i] << " ";
    // }
    //打印二维vector
    cout << "[";
    for(int i = 0; i < result.size(); ++i){
        vector<string> temp = result[i];
        cout << "[";
        for(int j = 0; j < temp.size(); ++j){
            cout << temp[j];
            if(j != temp.size() - 1) cout << ", ";
        }
        cout << "]";
        if(i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << endl;
    return 0;
}

