/**
 * https://leetcode.cn/problems/sliding-window-maximum/
*/

#include <bits/stdc++.h>
using namespace std;

class MyQueue{ //单调队列
    public:
        deque<int> que; //双向队列
        void pop(int value){ 
            if(!que.empty() && value == que.front()){ //是最大值才弹出
                que.pop_front();
            }
        }
        void push(int value){ //每次push一个值的时候，把小于这个值的元素全删了
            while(!que.empty() && value > que.back()){
                que.pop_back();
            }
            que.push_back(value);
        }
        int front(){
            return que.front();
        }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQueue que; // 单调队列，由大到小
        for(int i = 0; i < k; ++i){
            que.push(nums[i]);
        }
        result.push_back(que.front()); //保存结果
        for(int i = k; i < nums.size(); ++i){
            que.pop(nums[i - k]); //弹出对头元素
            que.push(nums[i]); //滑动窗口钱加入最后面的元素
            result.push_back(que.front());
        }
        return result;
    }
private:
    vector<int> result;
}; //分号

int main(){
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution solu;
    vector<int> result = solu.maxSlidingWindow(nums, 3);
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    return 0;
}