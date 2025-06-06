#include <bits/stdc++.h>

using namespace std;

void dfs(vector<vector<int>> &AL, int start, vector<int> &visited, int group){
    visited[start] = group;
    for(int u: AL[start]){
        if(visited[u] != -1){
            continue;
        }
        dfs(AL, u, visited, group);
    }
}

int main() {
    vector<vector<int>> AL = {
        {},                 //0
        {2, 3},             //1
        {1, 3},             //2
        {1, 2},             //3
        {5},                //4
        {4, 7},             //5
        {7},                //6
        {5, 6}              //7
    };
    
    vector<int> visited(AL.size(), -1);
    
    int group = 0;
    for(int i = 0; i < AL.size(); i++){
        if(visited[i] != -1){
            continue;
        }
        group++;
        dfs(AL, i, visited, group);
    }
    
    for(int i = 0; i<visited.size(); i++){
        cout << i << " group: " << visited[i] << "\n";
    }

    return 0;
}