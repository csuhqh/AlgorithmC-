/**
 * https://leetcode.cn/problems/next-greater-element-i/
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        stack<int> sta; //栈中只存下标
        //构造单调栈过程
        for(int i = 0; i < nums2.size(); ++i){ //遍历nums2中每个元素
            while(!sta.empty() && nums2[sta.top()] < nums2[i]){ //比该元素小的全部出栈
              map[nums2[sta.top()]] = i; //最后一个出栈的元素，本元素
              cout << sta.top() << " ";
              sta.pop();
            }
            cout << endl;
            sta.push(i); //下标入栈
        }
        vector<int> res(nums1.size());
        for(int i = 0; i < nums1.size(); ++i){
          int num = nums1[i];
          if(map.find(num) != map.end()){
            res[i] = nums2[map[num]];
          }else res[i] = -1;
        }
        return res;
    }
};
int main(){
  return 0;
}