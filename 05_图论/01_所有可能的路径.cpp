/**
 * https://leetcode.cn/problems/all-paths-from-source-to-target/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {d
public:
    vector<vector<int>> result; 
    vector<int> path;
    int n = -1;

    void backDfs(vector<vector<int>>& graph, int x){
        if(x == graph.size() - 1){ //回溯退出条件
            result.push_back(path);
            return;
        }

        for(int i = 0; i < graph[x].size(); ++i){
            path.push_back(graph[x][i]);
            backDfs(graph, graph[x][i]);
            path.pop_back();
        }


    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        vector<bool> visited(n, false);
        backDfs(graph, 0);


        return result;


    }
};