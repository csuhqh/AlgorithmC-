/*
https://leetcode.cn/problems/implement-stack-using-queues/
*/
#include <bits/stdc++.h>
using namespace std;

class MyStack {
public:
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
    }
    
    int pop() {
        int size = que1.size();
        while(size > 1){ //剩下最后一个元素
            que2.push(que1.front());
            que1.pop();
            size--;
        }
        // 取出队尾
        int res = que1.front();
        que1.pop();
        //将队列2移到队列1，并清空队列2
        swap(que1, que2);
        return res;
    }
    
    int top() { //top为队列的尾巴
        return que1.back();
    }
    
    bool empty() {
        return que1.empty();
    }
private:
    queue<int> que1;
    queue<int> que2;
};




int main(){
    MyStack* my = new MyStack();
    my->push(1);
    my->push(2);
    cout << my->top() << endl;
    cout << my->pop() << endl;
    cout << my->empty() << endl;

    return 0;
}