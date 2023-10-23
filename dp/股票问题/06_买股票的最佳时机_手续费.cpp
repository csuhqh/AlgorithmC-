/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
*/
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2, 0));
        dp[0][0] = -50001;
        for(int i = 1; i <= prices.size(); ++i){
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i - 1]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i - 1] - fee);  
        }
        return dp[prices.size()][1];
    }
};


int main(){
    vector<int> prices = {1, 3, 2, 8, 4, 9};
    int fee = 2;
    Solution solu;
    int res = solu.maxProfit(prices, fee);
    cout << res << endl;
    return 0;
}
