/**
 * https://leetcode.cn/problems/binary-search/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;  //注意这里size - 1
        int middle = -1;
        while(low <= high){
            middle = (low + high) / 2;
            if(nums[middle] < target){
                low = middle + 1;
            }else if(nums[middle] > target){
                high = middle - 1;
            }else{
                return middle;
            }
        };
        return -1;

    }
};


int main(){
    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;
    Solution solu;

    int res = solu.search(nums, target);
    cout << res << endl;



    return 0;
}