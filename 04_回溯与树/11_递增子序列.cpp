/**
 * url:https://leetcode.cn/problems/non-decreasing-subsequences/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> findSubsequences(vector<int>& nums){
            backtracking(nums, 0);
            return result;
        }
    private:
        vector<vector<int>> result;
        vector<int> path;
        void backtracking(vector<int>& nums, int startIndex){
            if(path.size() >= 2){
                result.push_back(path);
                // return;  这里不能加return，要去树上的节点
            }
            unordered_set<int> uset;
            for(int i = startIndex; i < nums.size(); ++i){
                if(uset.find(nums[i]) != uset.end() || !path.empty() && nums[i] < path.back()) continue; //去重 + 确保单调
                uset.insert(nums[i]); //保证同一层下不重复
                path.push_back(nums[i]);
                backtracking(nums, i + 1);
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
    vector<int> nums = {4,6,7,7};
    Solution solu;
    vector<vector<int>> result = solu.findSubsequences(nums);

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

