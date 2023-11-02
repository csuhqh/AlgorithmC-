## 方法归类
## 易错
1. 在类中，不要在变量定义时初始化，或者每次使用它之前要注意：https://leetcode.cn/problems/balanced-binary-tree/


### 树模版
```
int dep = 0;
int maxDep = 0;
void dfs(NodeList* root){
  //单独处理空根
  if(root == nullptr) return;
  //处理当前节点
  dep++;
  if(当前节点是叶子){ //可能有return,也可能没有}
  dfs(root->left); //处理当前节点的孩子
  dfs(root->right);
  dep--;
}
```
### 类树模版
void dfs(likeTree* NodeList, int start){
  //退出条件 （例如路径长度）
  if(){ }
  for(){ //处理当前节点的孩子节点
    dfs(node)
    path.pop_back(); //回溯  （每次处理完一个孩子都要回溯）
  }

}

### dfs, bfs, 


## 适合题型
需要遍历所有可能的结果（图中两个节点的所有可能路径）