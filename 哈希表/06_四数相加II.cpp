/**
 * url:https://leetcode.cn/problems/4sum-ii/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4){
            unordered_map<int, int> SUM1;
            for(int a: nums1){
                for(int b:nums2){
                    SUM1[a+b]++;
                }
            }
            unordered_map<int, int> SUM2;
            for(int a:nums3){
                for(int b:nums4){
                    SUM2[a + b]++;
                }
            }
            int count = 0;
            for(auto it: SUM1){
                if(SUM2.find(-it.first) != SUM2.end()){
                    count += it.second * SUM2[-it.first];
                }
            }
            return count;
        }
};


int main(){
    Solution solu;
    vector<int> nums1 = {1, 2};
    vector<int> nums2 = {-2, -1};
    vector<int> nums3 = {-1, 2};
    vector<int> nums4= {0, 2};


    int result = solu.fourSumCount(nums1, nums2, nums3, nums4);

    cout << "result: ";

    //打印普通
    cout << result << endl;
    //打印vector
    // for(int i = 0; i < result.size(); ++i){
    //     cout << result[i] << " ";
    // }

    cout << endl;
    return 0;
}

