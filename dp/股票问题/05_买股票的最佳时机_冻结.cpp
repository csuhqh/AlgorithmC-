/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-cooldown/
*/
#include "iostream"
#include "vector"
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(3));
        dp[0][1] = -1001;
        // dp[1][0] = 0;
        // dp[1][1] = -prices[0];
        // dp[1][2] = 0;
        for(int i = 1; i <= prices.size(); ++i){
            dp[i][0] = dp[i - 1][0];
            if(i >= 2){
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][2] - prices[i - 1]); //持有
            }else{
                dp[i][1] = max(dp[i - 1][1],  - prices[i - 1]); //持有
            }
            
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i - 1]);
        }
        return dp[prices.size()][2];
    }

    
};

int main(){
    vector<int> prices = {1,2,3,0,2};
    Solution solu;
    int res = solu.maxProfit(prices);
    cout << res << endl;
    return 0;
}


