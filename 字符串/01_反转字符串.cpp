/**
 * url:https://leetcode.cn/problems/reverse-string/
 * 反转问题：双指针法
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void reverseString(vector<char>& s){
            int i = 0, j = s.size() - 1;
            for(; i < s.size() / 2; ++i, --j){
                swap(s[i], s[j]);
            }

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
    vector<char> s = {'h','e','l','l','o'};
    Solution solu;
    solu.reverseString(s);
    vector<char> result;
    result.assign(s.begin(), s.end());
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

