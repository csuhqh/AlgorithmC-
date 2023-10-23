/*
https://leetcode.cn/problems/evaluate-reverse-polish-notation/
*/
#include <bits/stdc++.h>
using namespace std;

/**
 * 数字字符串 转 数字要看是否有负数。
*/

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result = 0;
        if (tokens.size() == 1) return str2int(tokens[0]);
        stack<string> st;
        unordered_set<string> ops = {"+", "-", "*", "/"};
        for(int i = 0; i < tokens.size(); ++i){
            string c = tokens[i];
            if(ops.find(c) != ops.end()){
                string right = st.top();
                st.pop();
                string left = st.top();
                st.pop();
                result = op(str2int(left), str2int(right), c);
                st.push(to_string(result));
            }else{
                st.push(c);
            }
        }
        return result;
    }

    int str2int(string s){
        // if (s[0] == '-') return -str2int(s.substr(1, s.size()));
        // if (s[0] == '+') return str2int(s.substr(1, s.size()));
        // int res = 0;
        // for(int i = 0; i < s.length(); ++i){
        //     res *= 10;
        //     res += s[i] - '0';
        // }
        // return res;
        return atoi(s.data());
    }
    int op(int a, int b, string s){
        if(s == "+") return a + b;
        else if(s == "-") return a - b;
        else if(s == "*" ) return a * b;
        else return a / b;

    }
};

int main(){
    vector<string> tokens = {"2","1","+","3","*"};
    Solution solu;
    int res = solu.evalRPN(tokens);
    cout << res << endl;
}