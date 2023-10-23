/**
 * url:https://leetcode.cn/problems/4sum/
*/

#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> result;
            for(int i = 0; i < nums.size(); ++i){
                if(i > 0 && nums[i] == nums[i - 1]) continue;
                for(int j = i + 1; j < nums.size(); ++j){
                    if(j > i + 1 && nums[j] == nums[j - 1]) continue;
                    int left = j + 1;
                    int right = nums.size() - 1;
                    while(left < right){
                        long sum = (long)nums[i] + nums[j] + nums[left] + nums[right];
                        if(sum == target){
                            result.push_back(vector<int>{nums[i], nums[j], nums[left], nums[right]});
                            while(left < right && nums[left] == nums[left + 1]) ++left;
                            while(left < right && nums[right] == nums[right - 1]) --right;
                            left++;
                            right--;
                        }else if(sum > target){
                            --right;
                        }else{
                            ++left;
                        }
                    }
                }

            }

            return result;
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
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    Solution solu;
    vector<vector<int>> result = solu.fourSum(nums, target);

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

