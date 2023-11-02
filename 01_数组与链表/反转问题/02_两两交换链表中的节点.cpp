/**
 * https://leetcode.cn/problems/swap-nodes-in-pairs/
*/
//设置虚拟节点。
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //通过设置虚拟头结点，每次temp都是指向新的3个节点。
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode* temp = dummyNode;
        while(temp && temp->next && temp->next->next){
            ListNode* pre = temp->next;
            ListNode* cur = pre->next;
            ListNode* t = cur->next;
            temp->next = cur;
            cur->next = pre;
            pre->next = t;
            temp = pre;
        }
        return dummyNode->next;
    }
};


//优化
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        //通过设置虚拟头结点，每次temp都是指向新的3个节点。
        ListNode* dummyNode = new ListNode();
        dummyNode->next = head;
        ListNode* temp = dummyNode;
        while(temp && temp->next && temp->next->next){
            ListNode* pre = temp->next;
            ListNode* cur = pre->next;
            pre->next = cur->next;
            cur->next = pre;
            temp->next = cur;
            temp = pre;
        }
        return dummyNode->next;
    }
};