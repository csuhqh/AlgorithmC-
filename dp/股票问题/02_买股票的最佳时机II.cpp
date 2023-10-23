#include "iostream"
#include "vector"
using namespace std;
/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock-ii/
*/
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 天数为i天时
        vector<vector<int>> dp(prices.size() + 1, vector<int>(2));
        dp[0][0] = -10001;
        dp[0][1] = 0;
        for(int j = 1; j <= prices.size(); ++j){
            dp[j][0] = max(dp[j - 1][0], dp[j - 1][1]-prices[j - 1]); //持有
            dp[j][1] = max(dp[j - 1][1], dp[j - 1][0] + prices[j - 1]);
        }
        return max(dp[prices.size()][0], dp[prices.size()][1]);
    }
};

int main(){
    vector<int> prices = {7,1,5,3,6,4};
    Solution solu;
    int res = solu.maxProfit(prices);
    cout << res << endl;
    return 0;
}