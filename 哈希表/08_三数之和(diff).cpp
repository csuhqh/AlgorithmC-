/**
 * url:https://leetcode.cn/problems/3sum/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            vector<vector<int>> result;
            sort(nums.begin(), nums.end(), less<int>{}); //升序
            for(int i = 0; i < nums.size(); ++i){
                if(nums[i] > 0) return result; //优化：排序后如果第一个元素>0，表示不可能有0
                if(i > 0 && nums[i] == nums[i - 1]) continue;
                int left = i + 1;
                int right = nums.size() - 1;
                while(right > left){
                    if(nums[i] + nums[left] + nums[right] > 0) right--;
                    else if(nums[i] + nums[left] + nums[right] < 0) left++;
                    else{
                        result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        while(right > left && nums[right] == nums[right - 1]) right--; //左移
                        while(right > left && nums[left] == nums[left + 1]) left++; //右移
                        //找到答案，两边指针收缩
                        right--;
                        left++;
                    }
                }

            }
            return result;
        }
};


int main(){
    Solution solu;
    vector<int> nums = {-1,0,1,2,-1,-4};

    vector<vector<int>> result = solu.threeSum(nums);

    cout << "result: ";

    //打印普通
    // cout << result << endl;
    //打印一维度vector
    // for(int i = 0; i < result.size(); ++i){
    //     cout << result[i] << " ";
    // }
    //打印二维
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

