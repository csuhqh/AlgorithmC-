/**
 * url:https://leetcode.cn/problems/reverse-words-in-a-string/
*/

#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
        void reverse(string& s, int start, int end){ //翻转，区间写法：左闭右闭 []
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }
        void removeExtraSpaces(string& s){
            
            int slow = 0;
            for(int i = 0; i < s.size(); ++i){ //往后跳一格
                if (slow != 0) s[slow++] = ' '; //手动控制空格，给单词之间添加空格。slow != 0说明不是第一个单词，需要在单词前添加空格。
                while (i < s.size() && s[i] != ' ') { //补上该单词，遇到空格说明单词结束。
                    s[slow++] = s[i++];
                }
            }
            
            s.resize(slow);
        }
        
        string reverseWords(string s){
            removeExtraSpaces(s); //去除多余空格，保证单词之间之只有一个空格，且字符串首尾没空格。
            reverse(s, 0, s.size() - 1); //整体反转
            int start = 0; //removeExtraSpaces后保证第一个单词的开始下标一定是0。
            for (int i = 0; i <= s.size(); ++i) { //单个单词反转
                if (i == s.size() || s[i] == ' ') { //到达空格或者串尾，说明一个单词结束。进行翻转。
                    reverse(s, start, i - 1); //翻转，注意是左闭右闭 []的翻转。对单词进行翻转
                    start = i + 1; //更新下一个单词的开始下标start
                }
            }
            return s;
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
    string s = "the sky is blue";
    
    Solution solu;
    string result = solu.reverseWords(s);

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