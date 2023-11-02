/**
 * https://leetcode.cn/problems/remove-element/submissions/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int len = nums.size();
        int i = 0;
        // for(int j = 0; j < len; ++j){
        //     while(j < len && nums[j] == val){ //检查下标
        //         ++j; //遇到该值删除
        //     }
        //     if(j >= len) break;  //在循环体内，如果改动循环指针，需要检测下标
        //     nums[i] = nums[j];
        //     ++i;
        // }

        for(int j = 0; j < len; ++j){
            if(nums[j] != val){
                nums[i] = nums[j];
                ++i;
            }
        }
        nums.assign(nums.begin(), nums.begin() + i);
        return nums.size();
    }
};

int main(){
    vector<int> nums = {3,2,2,3};
    int val = 3;
    Solution solu;


    int res = solu.removeElement(nums, val);
    cout << res << endl;
    for(int i = 0; i < nums.size(); ++i){
        cout << nums[i] << " ";
    }
}