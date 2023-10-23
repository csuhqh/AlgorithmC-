/**
 * https://leetcode.cn/problems/top-k-frequent-elements/
*/
#include <bits/stdc++.h>
using namespace std;

//自定义比较函数
// class mycomparison{
//     public:
//         bool operator()(const pair<int, int>& lhs, const pair<int, int>& chs){ //自定义比较函数
//             return lhs.second > chs.second;
//         }
// };
//方式一
static bool com1(pair<int, int> lhs, pair<int, int> chs){
    return lhs.second < chs.second;  //定义grater()
}
// priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&com1)> pri_que(com1); //优先级队列的使用
//方式二
class Cmp2{
    public:
        bool operator()(pair<int, int> lhs, pair<int, int> chs){
            return lhs.second > chs.second;  //定义grater()
        }
};
// priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp2> pri_que; //优先级队列的使用


class Solution {
public:



    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> map;
        for(int num: nums){
            map[num]++;
        }
        //定义大根
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&com1)> pri_que(com1);
        // for(int i = 0; i < map.size(); ++i){
        //     // pri_que.push(map[i]);
        //     pri_que.push(map[i]);
        // }   
        for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); ++it){
            pri_que.push(*it); //这样就可以，但是前面那样就不写
        }
        for(int i = 0; i < k; ++i){
            result.push_back(pri_que.top().first);
            pri_que.pop();
            
        }
        

        // //定义小顶堆(传入greater)
        // priority_queue<pair<int, int>, vector<pair<int, int>>, Cmp2> pri_que; //优先级队列的使用

        // //用固定大小为k的小顶堆
        // for(unordered_map<int, int>::iterator it = map.begin(); it != map.end(); ++it){
        //     pri_que.push(*it); 
        //     if(pri_que.size() > k){ //保证堆的大小
        //         pri_que.pop(); 
        //     }
        // }
        // // 找出前K个高频元素，因为小顶堆先弹出的是最小的，所以倒序来输出到数组
        // vector<int> result(k);
        // for (int i = k - 1; i >= 0; i--) {
        //     result[i] = pri_que.top().first;
        //     pri_que.pop();
        // }
        return result;
    }
};

int main(){
    Solution solu;
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    vector<int> res = solu.topKFrequent(nums, 2);
    for(int i: res){
        cout << i << " ";
    }
    return 0;
}