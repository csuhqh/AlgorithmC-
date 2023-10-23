/**
 * url: https://leetcode.cn/problems/3sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> threeSum(vector<int>& nums){
            vector<vector<int>> result;
            sort(nums.begin(), nums.end(), less<int>{});
            


            for(int i = 0; i < nums.size(); ++i){
                if(i > 0 && nums[i] == nums[i - 1]) continue; //去除重复
                int j = nums.size() - 1;
                int k = i + 1;
                while(j > k){
                    //当条件不符合时指针的移动
                    if(nums[i] + nums[j] + nums[k] > 0) --j;
                    else if(nums[i] + nums[j] + nums[k] < 0) ++k;
                    //当条件符合时，指针的移动
                    else{ 
                        result.push_back(vector<int>{nums[i], nums[j], nums[k]}); //这里的去重必须在找到，++
                        while(j > k && nums[j] == nums[j - 1]) --j;
                        while(j > k && nums[k] == nums[k + 1]) ++k;
                        j--;
                        ++k;
                    }
                    //去除重复
                    // while(j > k && nums[j] == nums[j - 1]) --j;
                    // while(j > k && nums[k] == nums[k + 1]) ++k;
                    // //
                    // if(nums[i] + nums[j] + nums[k] == 0){
                    //     result.push_back(vector<int>{nums[i], nums[j], nums[k]});
                    //     ++k;--j;
                    // }else if(nums[i] + nums[j] + nums[k] > 0) --j;
                    // else ++k;
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
    vector<int> nums = {-1, 0, 0, 0};
    Solution solu;
    vector<vector<int>> result = solu.threeSum(nums);

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

