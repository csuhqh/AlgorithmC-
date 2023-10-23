/**
 * https://leetcode.cn/problems/design-linked-list/
 */
#include <bits/stdc++.h>
using namespace std;

/**
 * 在temp=head后，可以通过while(index--) temp = temp->next;  获取指定index的前驱
*/

class MyLinkedList {
public:
    MyLinkedList() {
        head = new Node(-1);
        len = 0;
    }
    
    int get(int index) {
        if(len == 0) return -1;
        if(index >= len) return -1;
        Node* temp = head;
        while(index--){ //指定下标的前驱
            temp = temp->next;
        }
        return temp->next->val;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(len, val);

    }
    
    void addAtIndex(int index, int val) {
        Node* temp = head;
        int i = 0;
        if(index < 0) index = 0;
        if(index > len) return;

        while(index--){
            temp = temp->next;
        }
        Node* p = new Node(val);
        p->next = temp->next;
        temp->next = p;
        len += 1;
    }
    
    void deleteAtIndex(int index) {
        if(index < 0) index = 0;
        if(index >= len) return;
        Node* temp = head;
        while(index--){
            temp = temp->next;
        }
        
        Node* p = temp->next;
        temp->next = temp->next->next;
        delete(p);
        len -= 1;

    }
    void traceList(){
        Node* temp = head->next;
        cout << "打印链表数据: ";
        while (temp)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }

private:
    typedef struct Node{
        int val;
        Node* next;
        Node(int val):val(val), next(nullptr){}
        Node():val(-1), next(nullptr){}
    }Node;
    Node* head;
    int len;
};



int main(){
    MyLinkedList myLinkedList;
    myLinkedList.addAtHead(1);
    myLinkedList.addAtTail(3);
    myLinkedList.traceList();
    myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
    myLinkedList.traceList();
    myLinkedList.get(1);              // 返回 2
    myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
    myLinkedList.traceList();
    int a = myLinkedList.get(1);              // 返回 3
    cout << "res " << a << endl;
    myLinkedList.traceList();
    return 0;
}
