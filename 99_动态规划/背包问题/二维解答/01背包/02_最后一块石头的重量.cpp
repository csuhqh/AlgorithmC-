/**
 * https://leetcode.cn/problems/last-stone-weight-ii/
*/
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
      int sum = 0;
      for(int i = 0; i < stones.size(); ++i){
        sum += stones[i];
      }
      int capacity = sum / 2;
      //1. dp[i][j] ==> 第 i - 1个物品，容量为j的背包，可以最大价值
      vector<vector<int>> dp(stones.size(), vector<int>(capacity + 1));
      //2. init
      //dp[x][0] = 0
      //dp[0][x] = ?
      for(int i = 0; i <= capacity; ++i){
        dp[0][i] = stones[0] <= i ? stones[0] : 0;
      }
      //3. 递推
      for(int i = 1; i < stones.size(); ++i){
        for(int j = 1; j <= capacity; ++j){ //j从1开始，因为j = 0已经初始化啦
          if(j >= stones[i]){
            dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - stones[i]] + stones[i]); //容量为j - stones[i + 1]
          }else{
            dp[i][j] = dp[i - 1][j];
          }  
        }
      }
      cout << sum << " " << dp[stones.size() - 1][capacity] << endl;
      return sum - 2 * dp[stones.size() - 1][capacity];
    }
};

