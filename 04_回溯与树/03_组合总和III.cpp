/**
 * url:https://leetcode.cn/problems/combination-sum-iii/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> combinationSum3(int k, int n){
            result.clear();
            path.clear();
            backtracking(0, k, n, 1);
            return result;
        }
    private:
        vector<vector<int>> result; //存放结果集合
        vector<int> path; //符合条件的结果
        void backtracking(int sum, int k, int n, int startIndex){//1. 确定参数
            //优化：剪枝
            if(sum > n) return;
            //2. 确定终止条件
            if(path.size() == k && sum == n){
                result.push_back(path); //存放结果
                return;
            }
            //单层
            for(int i = startIndex; i <= 9; ++i){
                sum += i;
                path.push_back(i);
                backtracking(sum, k, n, i + 1);
                sum -= i; //回溯
                path.pop_back(); //回溯
            }
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
    int k = 3;
    int n = 7;
    Solution solu;
    vector<vector<int>> result = solu.combinationSum3(k, n);

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
        vector<int> temp = result[i];
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

