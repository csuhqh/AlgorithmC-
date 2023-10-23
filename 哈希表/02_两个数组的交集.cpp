/**
 * url:https://leetcode.cn/problems/intersection-of-two-arrays/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2){
            unordered_set<int> result_set;
            unordered_set<int> nums_set(nums1.begin(), nums1.end());
            for(int num: nums2){
                if(nums_set.find(num) != nums_set.end()){ //没有出现
                    result_set.insert(num);
                }
            }
            return vector<int>(result_set.begin(), result_set.end());
        }
};


int main(){
    Solution solu;
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};

    vector<int> result = solu.intersection(nums1, nums2);
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << endl;
    }

    return 0;
}