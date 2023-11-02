/**
 * https://leetcode.cn/problems/all-paths-from-source-to-target/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<int> path;
    vector<vector<int>> res;

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        dfs(graph, 0);
        return res;
    }


    void dfs(vector<vector<int>>& graph, int start){
        //处理节点
        cout << start << endl;
        cout << "size: " <<  graph[start].size() << endl;
        path.push_back(start);

        if(start == n - 1){
            res.push_back(path);
            return;
        }


        //处理节点的孩子节点
        for(int i = 0; i < graph[start].size(); ++i){
            dfs(graph, graph[start][i]);
            path.pop_back();
        }
        


    }
};