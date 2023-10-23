/**
 * url:https://leetcode.cn/problems/valid-anagram/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        bool isAnagram(string s, string t){  
            if(s.length() != t.length()) return false;
            // vector<int> count(24, 0);
            int count[26] = {0}; //注意是26个英文字母
            for(int i = 0; i < s.length(); ++i){
                cout << s[i] << " " << s[i] - 'a' << endl;
                count[s[i] - 'a'] += 1;
            }
            for(int i = 0; i < t.length(); ++i){
                count[t[i] - 'a'] -= 1;
            }
            for(int i = 0; i < 26; ++i){
                if(count[i] != 0) return false;
            }
            return true;
        }
};


int main(){
    Solution solu;
    string s = "zlap";
    string t = "kcqx";

    bool result = solu.isAnagram(s, t);
    cout << result << endl;
    return 0;
}