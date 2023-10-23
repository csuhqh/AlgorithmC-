/**
 * 
*/
#include "iostream"
#include "vector"
using namespace std;

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        k = 2 * k + 1;  //状态数量
        vector<vector<int>> dp(prices.size() + 1, vector<int>(k, 0));
        for(int i = 0; i < k; ++i){
            if(i % 2 == 1){
                dp[0][i] = -100001;
            }
        }
        for(int i = 1; i <= prices.size(); ++i){
            for(int j = 0; j < k; ++j){
                if(j == 0){
                    dp[i][j] = dp[i - 1][j];
                    continue;
                }
                if(j % 2 == 1){
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] - prices[i - 1]); //买
                }else{
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + prices[i - 1]); //卖
                }
                
            }
        }
        return dp[prices.size()][k - 1];

    }
};


int main(){
    int k = 2;
    vector<int> prices = {3,2,6,5,0,3};
    Solution solu;
    int res = solu.maxProfit(k, prices);
    cout << res << endl;
    return 0;
}