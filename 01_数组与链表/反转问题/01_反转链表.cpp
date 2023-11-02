/**
 * https://leetcode.cn/problems/reverse-linked-list/
*/

/**
 * 一定要保证，尾巴->next = nullptr;
*/

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* pre = head;
        ListNode* cur = pre->next;
        ListNode* temp = nullptr;
        while(cur){
           temp = cur->next;
           cur->next = pre;
           pre = cur;
           cur = temp;
        }
        return pre;
    }
};