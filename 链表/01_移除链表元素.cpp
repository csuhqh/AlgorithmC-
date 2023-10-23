/**
 * https://leetcode.cn/problems/remove-linked-list-elements/
 */
#include <bits/stdc++.h>
using namespace std;

typedef struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr){};
} ListNode;

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

class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *res = nullptr;
        ListNode *cur = head;     // 当前节点
        ListNode *temp = nullptr; // 用来释放
        //找到第一个非删除节点
        while(cur && cur->val == val){ 
            temp = cur;
            cur = cur->next;
            delete(temp);
        }
        res = cur;
        if(res == nullptr) return res;
        //删除节点
        while(cur->next){
            if(cur->next->val == val){
                temp = cur->next;
                cur->next = cur->next->next;
                delete(temp);
            }else{
                cur = cur->next;
            }
        }
        return res;
    }
};

int main()
{
    vector<int> nums = {1, 2, 6, 3, 4, 5, 6};
    ListNode *head = nullptr;
    buildList(head, nums);
    traceList(head);

    Solution solu;
    int val = 6;
    ListNode *res = solu.removeElements(head, val);
    traceList(res);
    return 0;
}