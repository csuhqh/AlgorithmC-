/**
 * https://leetcode.cn/problems/remove-nth-node-from-end-of-list/
*/
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* pre = dummy; //指向要删除节点的pre
        ListNode* rear = pre; //rear指向尾巴节点
        while(n && rear->next){ 
            rear = rear->next;
            --n;
        }
        if(n != 0) return dummy->next;
        while(rear->next){
            pre = pre->next;
            rear = rear->next;
        }
        cout << pre->val << " " << rear->val << endl;
        if(pre->next) pre->next = pre->next->next;
        return dummy->next;
    }
};