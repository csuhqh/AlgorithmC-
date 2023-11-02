/**
 * url:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
         vector<string> findItinerary(vector<vector<string>>& tickets){
            targets.clear();
            for(const vector<string>& vec : tickets){
                targets[vec[0]][vec[1]]++; //记录映射关系 （默认是字典排序）
            }
            result.push_back("JFK");
            backtracking(tickets.size());
            return result;
        }
    private:
        vector<string> result;
        unordered_map<string, map<string, int>> targets; //从A地区到B地区的
        bool backtracking(int ticketNum){ //每次选择最优，并且不回溯
            if(ticketNum + 1 == result.size()){ //到达叶子节点，退出
                return true;
            }
            for(pair<const string, int>& target: targets[result[result.size() - 1]]){
                if(target.second > 0){ //用来记录有没有走过
                    result.push_back(target.first);
                    target.second--;
                    if(backtracking(ticketNum)) return true;
                    result.pop_back();
                    target.second++;
                    
                }

            }
            return false;

        }
};


int main(){
    //输入数据: 数值输入
    // int a, b;
    // cin >> a >> b;
    // cout << "输入:" << a << " " << b << endl;
    //字符串输入
    // string s, e;
    // cin >> s >> e;
    // cout << "输入:" << s << " " << e <<  endl;
    //读取一行字符串（遇到回车）
    // string f;
    // cin.get();
    // getline(cin, f);
    // cout << "输入:" << f << endl;
    //逐个字符读取，可以读取任意字符(包括换行和回车) cin.get() 
    // int num;
    // while(cin >> num){
    //     if(cin.get() == '\n'){
    //         cout << num << endl;
    //     }
    // }
    //手工输入
    vector<vector<string>> tickets = {{"MUC", "LHR"}, {"JFK", "MUC"}, {"SFO", "SJC"}, {"LHR", "SFO"}};
    Solution solu;
    vector<string> result = solu.findItinerary(tickets);

    cout << "result: ";

    //打印普通
    // cout << result << endl;
    //打印vector
    for(int i = 0; i < result.size(); ++i){
        cout << result[i] << " ";
    }
    //打印二维vector
    // cout << "[";
    // for(int i = 0; i < result.size(); ++i){
    //     vector<int> temp = result[i];
    //     cout << "[";
    //     for(int j = 0; j < temp.size(); ++j){
    //         cout << temp[j];
    //         if(j != temp.size() - 1) cout << ", ";
    //     }
    //     cout << "]";
    //     if(i != result.size() - 1) cout << ", ";
    // }
    // cout << "]" << endl;

    cout << endl;
    return 0;
}

