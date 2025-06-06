// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>

using namespace std;

void dfs_rec(vector<vector<int>> &AL, int start, vector<bool> &visited){
    cout << start << " -> ";
    visited[start] = true;
    for(int u: AL[start]){
        if(visited[u]){
            continue;
        }
        dfs_rec(AL, u, visited);
    }
}

vector<bool> dfs(vector<vector<int>> &AL, int start){
    vector<bool> visited(AL.size(), false);
    dfs_rec(AL, start, visited);
    cout << "END\n";
    
    return visited;
}

vector<bool> dfs_it(vector<vector<int>> &AL, int start){
    vector<bool> visited(AL.size(), false);
    
    stack<int> next;
    next.push(start);
    
    while(!next.empty()){
        int u = next.top();
        next.pop();
        
        cout << u << " -> ";
        visited[u] = true;
        
        int j = AL[u].size()-1;
        for(int i=j; i>=0; i--){
            int v = AL[u][i];
            if(visited[v]){
                continue;
            }
            next.push(v);
        }
        
    }
    cout << "END\n";
    
    return visited;
    
}

int main() {
    vector<vector<int>> AL = {
        {},             //0
        {0, 2, 3, 4},   //1
        {3},            //2
        {6},            //3
        {3, 5},         //4
        {7},            //5
        {7},            //6
        {}              //7
    };
    
    dfs(AL, 4);
    cout << "--------------------\n";
    dfs_it(AL, 4);

    return 0;
}