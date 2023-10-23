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
      int capacity = sum / 2; //可以抵消的最多
      vector<int> dp(capacity + 1, 0);
      dp[0] = 0;
      for(int i = 0; i < stones.size(); ++i){
        for(int j = capacity; j >= 0; --j){
          if(j >= stones[i]) dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
          else dp[j] = max(dp[j], 0);
        }
      }
      return sum - 2 * dp[capacity];
    }
};

