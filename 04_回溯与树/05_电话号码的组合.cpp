/**
 * url:https://leetcode.cn/problems/letter-combinations-of-a-phone-number/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<string> letterCombinations(string digits){
            result.clear();
            s.clear();
            if(digits.size() == 0) return vector<string>{};
             backtracking(digits, 0);
            return result;
        }
    private:
        vector<string> result; //存放最终结果
        string s; //用来存放正确结果
        void backtracking(string digits, int startIndex){
            if(startIndex == digits.size()){
                result.push_back(s);
                return;
            }
            //去对于的集合
            string letter = letterMap[digits[startIndex] - '0'];
            for(int i = 0; i < letter.size(); ++i){
                s.push_back(letter[i]);
                backtracking(digits, startIndex + 1);//下一个集合取一个元素
                s.pop_back();
            }


        }


        const string letterMap[10] = {
        "", // 0
        "", // 1
        "abc", // 2
        "def", // 3
        "ghi", // 4
        "jkl", // 5
        "mno", // 6
        "pqrs", // 7
        "tuv", // 8
        "wxyz", // 9
        };
        
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
    string digits = "23";
    Solution solu;
    vector<string> result = solu.letterCombinations(digits);

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

