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


//new 
class MyStack {
private:
    queue<int> que1, que2;
    int len{0};
public:
    MyStack() {

    }
    
    void push(int x) {
        que1.push(x);
        ++len;
    }
    
    int pop() {
        for(int i = 0; i < len - 1; ++i){
            int num = que1.front();
            que1.pop();
            que2.push(num);
        }
        int num = que1.front();
        cout << "pop" << num << endl;
        que1.pop();
        --len;
        while(!que2.empty()){
            int temp = que2.front();
            que2.pop();
            que1.push(temp);
        }
        return num;

    }
    
    int top() {
        cout << len << endl;
        int num = pop();
        cout << len << endl;
        push(num); //易错，我写成了que2.push(num) 导致 len没有++
        cout << que1.back() << endl;
        cout << len << endl;
        return num;
    }
    
    bool empty() {
        return len == 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

int main(){
    MyStack* my = new MyStack();
    my->push(1);
    my->push(2);
    cout << my->top() << endl;
    cout << my->pop() << endl;
    cout << my->empty() << endl;

    return 0;
}

