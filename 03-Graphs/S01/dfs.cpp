#include "graph.hpp"

/*
vector<int> Graph::DFS(int start_node){
    vector<int> visited(num_nodes,-1);
    stack<int> S;

    visited[start_node] = 1;
    S.push(start_node);
    while(!S.empty()){
        int s = S.top();
        S.pop();
        for( int v: edges[s] )
            if( visited[v] == -1 ){
                visited[v] = 1;
                S.push(v);
            }
    }

    return visited;
}
*/

void Graph::DFS_aux(vector<int>* visited, int start_node, int* index){
    visited->at(start_node) = ++(*index);
    for( int v: edges[start_node] )
        if( visited->at(v) == -1 )
            DFS_aux(visited, v, index);
}

vector<int> Graph::DFS(int start_node){
    vector<int> visited(num_nodes,-1);
    int index = 0;

    DFS_aux(&visited, start_node, &index);    

    return visited;
}

void Graph::DFS_Topo(vector<int>* visited, vector<int>* f, int node, int* currLabel){
    visited->at(node) = 1;
    for( int v: edges[node] )
        if( visited->at(v) == -1 )
            DFS_Topo(visited, f, v, currLabel);
    f->at(node) = (*currLabel)--;
}

vector<int> Graph::TopoSort(){
    vector<int> visited(num_nodes,-1);
    vector<int> f(num_nodes,-1);
    int currLabel = num_nodes;

    for(int i = 0; i < num_nodes; ++i)
        if( visited[i] == -1 )
            DFS_Topo(&visited, &f, i, &currLabel);

    return f;
}

void Graph::SCC_aux(int node, vector<int>* disc, vector<int>* low, stack<int>* S, vector<bool>* stackMember, int* time, int* index){
    disc->at(node) = low->at(node) = ++(*time);
    S->push(node);
    stackMember->at(node) = true;

    for( int v: edges[node] ){
        if( disc->at(v) == -1 ){
            SCC_aux(v, disc, low, S, stackMember, time, index);
            low->at(node) = min(low->at(node), low->at(v));
        }else
            if( stackMember->at(v) == true )
                low->at(node) = min(low->at(node), disc->at(v));
    }

    if( low->at(node) == disc->at(node) ){
        int w;
        cout << "SCC #" << ++(*index) << ": ";
        while( S->top() != node ){
            w = S->top();
            cout << w << " ";
            stackMember->at(w) = false;
            S->pop();
        }
        w = S->top();
        cout << w << "\n";
        stackMember->at(w) = false;
        S->pop();
    }
}

void Graph::SCCs(){
    vector<int> disc(num_nodes, -1);
    vector<int> low(num_nodes, -1);
    vector<bool> stackMember(num_nodes, false);
    stack<int> S;
    int discovery_time = 0;
    int SCC_index = 0;

    for(int i = 0; i < num_nodes; ++i)
        if( disc[i] == -1 )
            SCC_aux(i, &disc, &low, &S, &stackMember, &discovery_time, &SCC_index);
}