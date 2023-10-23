/**
 * url: https://leetcode.cn/problems/4sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            vector<vector<int>> result;
            sort(nums.begin(),nums.end(), less<int>{});
            for(int k = 0; k < nums.size(); ++k){
            
                //对nums[k]去重
                if(k > 0 && nums[k] == nums[k - 1]) continue;


                for(int i = k + 1; i < nums.size(); ++i){
                    //对nums[i]去重
                    if(i > k + 1 && nums[i] == nums[i - 1]) continue;

                    int left = i + 1;
                    int right = nums.size() - 1;
                    while(right > left){
                        if((long)nums[k] + nums[i] + nums[left] + nums[right] > target) right--;
                        else if((long)nums[k] + nums[i] + nums[left] + nums[right] < target) left++;
                        else{
                            result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});

                            // 对nums[left]和nums[right]去重
                            while (right > left && nums[right] == nums[right - 1]) right--;
                            while (right > left && nums[left] == nums[left + 1]) left++;

                            // 找到答案时，双指针同时收缩
                            right--;
                            left++;
                        }
                    }
                }

            }

            return result;
        }
};


int main(){
    Solution solu;

    //手工输入
    vector<int> nums = {1,0,-1,0,-2,2};
    int target = 0;
    //自动输入(数值输入)
    // int a, b;
    // cin >> a >> b;






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

