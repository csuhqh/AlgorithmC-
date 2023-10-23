#include <bits/stdc++.h>
using namespace std;
/**
 * https://leetcode.cn/problems/implement-queue-using-stacks/submissions/
*/
class MyQueue {
public:
    MyQueue() {

    }
    
    void push(int x) {
        stack1.push(x);
    }
    
    int pop() { //出栈时，如果栈二为空，则把栈一全部倒入栈2
        if(stack2.empty()){
            while(!stack1.empty()){
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        int res = stack2.top();
        stack2.top();
        return res;
    }
    
    int peek() {
        int res = pop();
        stack2.push(res);
        return res;
    }
    
    bool empty() {
        return stack1.empty() && stack2.empty();
    }
private:
    stack<int> stack1;
    stack<int> stack2;
};

int main(){
    MyQueue* mq = new MyQueue();
    mq->push(1);
    mq->push(2);
    cout << mq->peek() << endl;
    mq->pop();
    cout << mq->empty() << endl;


    return 0;
}