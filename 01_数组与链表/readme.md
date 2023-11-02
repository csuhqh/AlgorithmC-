## 易错
1. 反转链表时，记得尾巴->next=nullptr;
2. 创建dummy时，记得dummy->next = heaad;
3. 不要while(n--)的形式。
4. 定义ListNode* a = headA, b = headB; 是错误的，应该时*b.


常用方法：
快慢指针，双指针
## 数组去重
slow fast指针秒杀， slow=0, fast=0 + gap， gap为需要保留的重复数量，去重则gap=0。 nums[slow+gap] = nums[fast;]
例如：删除所有值为val的元素，gap=0, 删除重复出现的数字，只保留一个，gap=1 (需要先排序)

## 数字和
注意外部去重与内部去重的区别。
112, 外部去重nums[i] == nums[i - 1]，使得使用第一个1时，包括12。如果使用nums[i] == nums[i + 1]，使得第一次使用1时，只有2。做3数之和这道题目自行体会

