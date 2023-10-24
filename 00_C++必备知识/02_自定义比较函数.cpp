#include<bits/stdc++.h>
using namespace std;


/**
 * 重载运算符
 * 参考: https://blog.csdn.net/qq_21539375/article/details/122128445
*/
/**
 * 通常自定义比较方式需要传入: 排序函数(如sort) / 排序函数类型(如: priority_queue)
*/
/**
 * 排序函数
*/
bool cmp(int &a, int &b){
  return a > b; //相当于greater，每次挑出最大的
}

int main(){
  //内置堆
  struct CMP{ 
    bool operator()(int a, int b){
      return a < b; //less，构建大顶堆。
    }
  };
  class CMP2{
    public:
      bool operator()(int a, int b){
      return a < b; //less，构建大顶堆。
    }
  };
  priority_queue<int, vector<int>, CMP> pq; 
  pq.push(1);
  pq.push(7);
  pq.push(0);
  cout << pq.top() << endl; // print 7


  return 0;
}