/**
 * https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
        reverse(s.begin(), s.end()); //字符串反转函数
        stack<char> st;
        for(char c: s){
            if(st.empty() || st.top() != c) st.push(c);
            else st.pop();
        }
        string res = "";
        while(!st.empty()){
            res += st.top();
            st.pop();
        }
        return res;
    }
};

int main(int argc, char* args[]){
    Solution solu;
    string s = "abbaca";
    cout << solu.removeDuplicates(s) << endl;

    return 0;
}