#include<bits/stdc++.h>
using namespace std;


/**
 * 重载运算符
 * 参考: https://blog.csdn.net/qq_21539375/article/details/122128445
*/
/**
 * 通常自定义比较方式需要传入: 排序函数(如sort) / 排序函数类型(如: priority_queue)
 * 建议统一使用struct，需要排序函数传入CMP(), 需要排序函数类型使用CMP.
*/

int main(){
  //内置堆
  struct CMP{ 
    bool operator()(int a, int b){
      return a < b; //less，构建大顶堆。
    }
  };
  class CMP2{
    public: //必须pulibc
      bool operator()(int a, int b){
      return a < b; //less，构建大顶堆。
    }
  };
  auto CMP3 = [](int &a, int &b){
    return a < b; //相当于less，每次挑出最小的
  };
  
  vector<int> nums = {1, 9, 4};
  printf("利用sort传入比较函数排序后:\n");
  sort(nums.begin(), nums.end(), CMP());
  for(int i = 0; i < nums.size(); ++i){
    printf("%d ", nums[i]);
  }

  printf("\n传入比较函数类型，排序:\n");
  priority_queue<int, vector<int>, CMP> pq;  //CMP为less，为大顶堆
  pq.push(1);
  pq.push(7);
  pq.push(0);
  cout << pq.top() << endl; // print 7


  return 0;
}