/**
 * url:https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int strStr(string haystack, string needle){
        int i=0,j=0;
        int temp=0;
        bool isMatch = false;
        for(int i = 0; i < haystack.size(); ++i){
            temp = i;  //要归位
            isMatch = true;
            for(int j = 0; j < needle.size(); ++j){
                if(i >= haystack.size()) return -1; 
                if(haystack[i] != needle[j]){   //判断条件中，如果有i < size()时，一定要判断是哪个条件没有满足。
                    isMatch = false;
                    break;
                }
                ++i;
            }
            i = temp; // 归位
            if(isMatch) return i;

        }
        return -1;
        // while(i<haystack.size()&&j<needle.size()){
        //     temp=i;
        //     while(i<haystack.size() && j<needle.size() && haystack[i]==needle[j]){
        //         i++;
        //         j++;
        //     }
        //     if(j==needle.size()){
        //         return i-needle.size();
        //     }
        //     i=temp+1;
        //     j=0;
        // }
        // return -1;
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
    string s = "dabc";
    string sub = "abc";
    Solution solu;
    int result = solu.strStr(s, sub);

    cout << "result: ";

    //打印普通
    cout << result << endl;
    //打印vector
    // for(int i = 0; i < result.size(); ++i){
    //     cout << result[i] << " ";
    // }
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

