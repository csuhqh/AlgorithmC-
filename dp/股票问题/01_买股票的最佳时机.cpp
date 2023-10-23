# include "iostream"
#include "vector"
using namespace std;

/**
 * https://leetcode.cn/problems/best-time-to-buy-and-sell-stock/
 * 
*/

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         //dp[i]
//         vector<int> dp(prices.size() + 1, 0);
//         int maxPro = -1;
//         int j = 1;
//         for(int i = prices.size(); i > 0; --i){
//             j = prices.size() - i + 1;
//             // cout << prices[i - 1] << " ";
//             dp[j] = max(prices[i - 1], dp[j - 1]);  //倒数j个数字的最大值
//             // cout << dp[j] << " ";
//             if (maxPro < dp[j] - prices[i - 1]){
//                 maxPro = dp[j] - prices[i - 1];
//             }

//         }
//         if (maxPro < 0) return 0;
//         return maxPro;
//     }
// };

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // 构造n * 2
        // vector<vector<int>> dp(prices.size() + 1, vector<int>(2));  // + 1不要忘
        // dp[0][0] = -10001; //记得
        // dp[0][1] = 0;
        // for(int i = 1; i <= prices.size(); ++i){
        //     //这里dp[i]只依赖于dp[i - 1]的状态，因此可以优化
        //     dp[i][0] = max(dp[i - 1][0], 0 - prices[i - 1]);
        //     dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i - 1]);

        // }

        //优化
        int dp[2][2] = {0};
        dp[0][0] = -10001;
        dp[0][1] = 0;
        for(int i = 1; i <= prices.size(); ++i){
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], -prices[i - 1]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1)%2][0] + prices[i - 1]);
        }
        return max(dp[prices.size() % 2][0], dp[prices.size() % 2][1]);
    }
};

int main(){
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    Solution solu;
    int res = solu.maxProfit(prices);
    cout << endl;
    cout << res << endl;
    return 0;
}