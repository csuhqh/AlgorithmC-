/**
 * https://leetcode.cn/problems/hua-dong-chuang-kou-de-zui-da-zhi-lcof/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxAltitude(vector<int>& heights, int limit) {
        vector<int> res;
        deque<int> dq;
        for(int i = 0; i < heights.size(); ++i){
            //从队尾开始，删除所有小于新元素的
            while(!dq.empty() && heights[dq.back()] < heights[i]){
                dq.pop_back();
            }
            //新元素进入队列
            dq.push_back(i);
            //移除队首元素，如果它不在窗口内
            if(i - dq.front() + 1 > limit){
                dq.pop_front();
            }
            //如果滑动窗口已经形成，则每次将队首元素加入
            if(i >= limit - 1){
                res.push_back(heights[dq.front()]);
            }
        }
        return res;
    }
};

int main(){

  return 0;
}