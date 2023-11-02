/**
 * https://leetcode.cn/problems/intersection-of-two-linked-lists-lcci/
*/

//最优接法
/**
A长度为 a, B长度为b， 假设存在交叉点，此时 A到交叉点距离为 c， 而B到交叉点距离为d
后续交叉后长度是一样的，那么就是 a-c = b-d -> a+d = b+c
这里意味着只要分别让A和B额外多走一遍B和A，那么必然会走到交叉，注意这里边缘情况是，大家都走到null依然没交叉，那么正好返回null即可
*/
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        //求交叉点 == 只要a, b 
        ListNode* a = headA, *b = headB;
        while(a != b){
            a = a == nullptr ? headB : a->next;
            b = b == nullptr ? headA : b->next;
        }
        return a;
    }
};