/**
 * https://leetcode.cn/problems/linked-list-cycle-ii/submissions/
*/


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head, *slow = head;
        //find the cycle
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow){ //存在环
                ListNode* t = head; //定义一个新的指针从起点开始，和慢指针共同前进
                while(t != slow){
                    slow = slow->next;
                    t = t->next;
                }
                return t;
            }
        }
        return nullptr;

    }
};