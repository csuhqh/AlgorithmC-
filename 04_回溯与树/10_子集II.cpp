/**
 * url:https://leetcode.cn/problems/subsets-ii/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            //需要排序
            sort(nums.begin(), nums.end());
            backtracking(nums, 0);
            return result;
        }
    private:
        vector<vector<int>> result;
        vector<int> path;
        void backtracking(vector<int>& nums, int startIndex){
            result.push_back(path);  //需要去树的子路径时，不需要。
            // if(startIndex >= nums.size()){
            //     result.push_back(path);
            //     return;
            // }
            for(int i = startIndex; i < nums.size(); ++i){
                if(i > startIndex && nums[i - 1] == nums[i]) continue;  //前提条件是排序
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
    vector<int> nums = {1, 2, 2};
    Solution solu;
    vector<vector<int>> result = solu.subsetsWithDup(nums);

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

