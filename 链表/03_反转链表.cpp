/**
 * https://leetcode.cn/problems/reverse-linked-list/
*/
#include <bits/stdc++.h>
using namespace std;


 struct ListNode {
     int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //双指针法
        ListNode* temp; //保存当前节点的下一个节点
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur){
            temp = cur->next; //相当于不断从元素链表中不断取下节点。
            cur->next = pre;
            pre = cur;
            cur = temp; //取出下一个
        }
        return pre;
        
    }
};


void buildList(ListNode *&head, vector<int> nums)
{
    ListNode *cur = head;
    ListNode *temp = nullptr;
    for (vector<int>::iterator it = nums.begin(); it != nums.end(); ++it)
    {
        if (head == nullptr)
        {
            head = new ListNode(*it);
            cur = head;
        }
        else
        {
            cur->next = new ListNode(*it);
            cur = cur->next;
        }
    }
}

void traceList(ListNode *head)
{
    cout << "打印链表数据: ";
    while (head)
    {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    ListNode* head = nullptr;
    vector<int> nums = {1, 2, 6, 3, 4, 5, 6};
    buildList(head, nums);
    Solution solu;
    head = solu.reverseList(head);
    traceList(head);
    return 0;
}


