/**
 * url:https://leetcode.cn/problems/combination-sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target){
            result.clear();
            path.clear();
            sort(candidates.begin(), candidates.end()); //提高效率
            backtracking(candidates, target, 0, 0);
            return result;
        }
    private:
        vector<vector<int>> result;
        vector<int> path;
        void backtracking(vector<int>& candidates, int target, int sum, int startIndex){
            if(sum == target){
                result.push_back(path);
                return;
            }

            for(int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; ++i){
                sum += candidates[i];
                path.push_back(candidates[i]);
                backtracking(candidates, target, sum, i);
                sum -= candidates[i];
                path.pop_back();
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
    vector<int> candidates = {2,3,6,7};
    int target = 7;
    Solution solu;
    vector<vector<int>> result = solu.combinationSum(candidates, target);

    cout << "result: ";

    //打印普通
    // cout << result << endl;
    //打印vector
    // for(int i = 0; i < result.size(); ++i){
    //     cout << result[i] << " ";
    // }
    // 打印二维vector
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

