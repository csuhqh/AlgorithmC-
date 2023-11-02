/**
 * url:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        vector<vector<string>> partition(string s){
            result.clear();
            path.clear();
            backtracking(s, 0);
            return result;
        }
    private:
        vector<vector<string>> result;
        vector<string> path; //可以直接存入的结果
        void backtracking(string s, int startIndex){
            if(startIndex >= s.size()){
                result.push_back(path);
                return;
            }
            for(int i = startIndex; i < s.size(); ++i){
                if(isHuiwen(s, startIndex, i)){ //是回文串，才考虑下面一部分
                    string str = s.substr(startIndex, i - startIndex + 1); //substr(0, len)
                    path.push_back(str);
                }else{ //不是回文串直接不考虑
                    continue;
                }
                backtracking(s, i + 1); //对剩下的串进一步
                path.pop_back();
            }

        }
        //判断是否是回文串
        bool isHuiwen(const string& s, int start, int end){
            for(int i = start, j = end; i < j; ++i, --j){
                if(s[i] != s[j]) return false;
            }
            return true;
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
    string s = "aba";
    Solution solu;
    vector<vector<string>> result = solu.partition(s);

    cout << "result: ";

    //打印普通
    // cout << result << endl;
    //打印vector
    // for(int i = 0; i < result.size(); ++i){
    //     cout << result[i] << " ";
    // }
    //打印二维vector
    cout << "[";
    for(int i = 0; i < result.size(); ++i){
        vector<string> temp = result[i];
        cout << "[";
        for(int j = 0; j < temp.size(); ++j){
            cout << temp[j];
            if(j != temp.size() - 1) cout << ", ";
        }
        cout << "]";
        if(i != result.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    cout << endl;
    return 0;
}

