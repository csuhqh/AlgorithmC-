/**
 * https://leetcode.cn/problems/valid-parentheses/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        if(s.length() % 2 == 1) return false;
        unordered_map<char, char> mp = {{'(',')'}, {'[', ']'}, {'{', '}'}};
        stack<char> st;
        for(int i = 0; i < s.length(); ++i){
            if(mp.find(s[i]) != mp.end()){ //左括号入栈
                st.push(s[i]);
            }else{ //右括号
                if(st.empty()) return false; //栈空
                if(s[i] != mp[st.top()]) return false; //栈顶与元素不匹配
                st.pop(); //匹配，出栈
            }

        }
        return st.empty(); //最后判断栈是否为空
    }
};

int main(int argc, char* args[]){
    string s = "()[]()";
    Solution solu;
    cout << solu.isValid(s) << endl;

    return 0;
}