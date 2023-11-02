/**
 * url:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums){
            sort(nums.begin(), nums.end()); // 排序
            vector<bool> used(nums.size(), false);
            backtracking(nums, used);
            return result;
        }
    private:
        vector<vector<int>> result;
        vector<int> path;
        void backtracking(const vector<int>& nums, vector<bool>& used){
            if(path.size() == nums.size()){
                result.push_back(path);
                return;
            }
            for(int i = 0; i < nums.size(); ++i){
                if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false) continue;

                if(used[i] == false){
                used[i] = true;
                path.push_back(nums[i]);
                backtracking(nums, used);
                path.pop_back();
                used[i] = false; //同一层可以相同
                }

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
    vector<int> nums = {1, 1, 2};
    Solution solu;
    vector<vector<int>> result = solu.permuteUnique(nums);

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

