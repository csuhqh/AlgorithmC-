/**
 * https://leetcode.cn/problems/merge-sorted-array/solutions/126371/88-by-ikaruga/?envType=study-plan-v2&envId=top-interview-150
*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1, j = n - 1, index = m + n - 1;
        while(i >= 0 && j >= 0){
            if(nums1[i] >= nums2[j]){
                nums1[index] = nums1[i];
                --index;
                --i;
            }else{
                nums1[index] = nums2[j];
                --index;
                --j;
            }
        }
        //只有可能是nums2还存在
        while(j >= 0){
            nums1[index] = nums2[j];
            index--;
            j--;
        }
    }
};