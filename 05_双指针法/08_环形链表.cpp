/**
 * url:https://leetcode.cn/problems/linked-list-cycle-ii/
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};

class Solution{
    public:
        ListNode *detectCycle(ListNode *head){
            ListNode* fast = head;
            ListNode* slow = head;
            while(fast && fast->next != nullptr){ //最后一个节点 
                slow = slow->next;
                fast = fast->next->next;
                if(slow == fast){ //环内相遇，一定有环
                    ListNode* index1 = fast;  //再来一个从头节点开始运动，一个从相遇节点开始运动，相遇节点为入口节点
                    ListNode* index2 = head;
                    while(index1 != index2){
                        index1 = index1->next;
                        index2 = index2->next;
                    }
                    return index2;
                }

            }

            return nullptr;
        }
};


void buildList(ListNode*& head, vector<int> nums){
    head = nullptr;
    ListNode* cur = nullptr;
    ListNode* temp = nullptr;
    for(int num: nums){
        if(head == nullptr){
            head = new ListNode(num);
            cur = head;
        }else{
            cur->next = new ListNode(num);
            cur = cur->next;
        }
    }
    temp = head;
    while(temp){
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;

}

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
    ListNode* head = nullptr;
    vector<int> nums = {3, 2, 0, -4};
    buildList(head, nums);
    Solution solu;
    ListNode* result = solu.detectCycle(head);

    cout << "result: ";
    cout << result->val << endl;
    //打印普通
    // cout << result << endl;
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

