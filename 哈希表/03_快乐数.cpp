/**
 * url:https://leetcode.cn/problems/happy-number/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        
        bool isHappy(int n){
            unordered_set<int> sums;
            int quare[10] = {0};
            for(int i = 0; i < 10; ++i){
                quare[i] = i * i;
            }
            int sum = 0;
            while(true){
                sum = 0;
                while(n){ //获取各个位置的和
                    sum += quare[n % 10];
                    n /= 10;
                }
                if(sums.find(sum) != sums.end()) return false; //如果存在该元素
                if(sum == 1) return true;
                sums.insert(sum);
                n = sum;
            }
        }
};


int main(){
    Solution solu;
    int n = 19;

    int result = solu.isHappy(n);

    //打印普通
    cout << "result: " << endl;
    cout << result << endl;
    //打印vector
    // for(int i = 0; i < result.size(); ++i){
    //     cout << result[i] << endl;
    // }
    return 0;
}
