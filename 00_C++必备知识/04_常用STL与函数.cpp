#include <bits/stdc++.h>
using namespace std;

int main(){
  //数据结构
  /**
   * 大顶堆: priority_queue: priority_queue<int, vector<int>, CMP> heap //定义一个堆
   * 双向队列: deque：front_pop/push(), back_pop/push(); back(), front();
   * 队列: queue: pop(), top(), push();
   * 数组: vector: 
   * 栈: stack: push, pop, top
   * 有序(无序)键值对: map(unordered_map): insert, erase
   * 有序(无序)集合: set(unordered_set): insert, erase
  */
  //函数
  /**
   * std::find(): 查找元素是否在容器中。 find(nums.begin(), nums.end(), num) != nums.end() 元素存在
   * std::sort(): 排序。默认升序，sort(nums.begin(), nums.end(), CMP())
   * reverse: 字符串反转, reverse(nums.begin(), nums.end())
  */
  // reverse
  string s = "abc";
  reverse(s.begin(), s.end());
  cout <<"reverse: " << s << endl;

}