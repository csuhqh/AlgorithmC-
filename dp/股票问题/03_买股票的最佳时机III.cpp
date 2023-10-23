/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-iii/
*/
#include "iostream"
#include "vector"
using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(5, 0));
        dp[0][1] = -100001;  //第一次买
        dp[0][3] = -100001; //第二次买
        for (int i = 1; i <= prices.size(); i++) {
            dp[i][0] = dp[i - 1][0];  //不买不卖
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i-1]); //第一次买
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] + prices[i-1]); //第一次卖
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] - prices[i-1]); //第二次买
            dp[i][4] = max(dp[i - 1][4], dp[i - 1][3] + prices[i-1]); //第二次卖
        }
        return dp[prices.size()][4];


    }
};


int main(){
    vector<int> prices = {1, 2, 3, 4, 5};
    Solution solu;
    int res = solu.maxProfit(prices);
    cout << res << endl;
    return 0;
}