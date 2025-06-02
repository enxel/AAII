#include "graph.hpp"

void print_vector(vector<int> V){
    for(int i = 0; i < V.size(); ++i)
        cout << V[i] << " ";
    cout << "\n";
}

Graph::Graph(int n){
    num_nodes = n;
    for(int i = 0; i < num_nodes; i++){
        vector<int> temp;
        edges.push_back(temp);
    }
}

void Graph::show_adjancencies(){
    for(int i = 0; i < edges.size(); i++){
        cout << "[ ";
        for(int j = 0; j < edges[i].size(); j++)
            cout << edges[i][j] << " ";
        cout << "]\n";
    }
}

void Graph::add_edge(int a, int b){
    edges[a].push_back(b);
}

void Graph::remove_edge(int a, int b){
    edges[a].erase( find( edges[a].begin(), edges[a].end(), b ) );
}

bool Graph::find_edge(int a, int b){
    return find( edges[a].begin(), edges[a].end(), b ) != edges[a].end();
}

vector<int> Graph::BFS_connectivity(int start_node){
    vector<int> visited(num_nodes,-1);
    queue<int> Q;

    visited[start_node] = 1;
    Q.push(start_node);
    while(!Q.empty()){
        int s = Q.front();
        Q.pop();
        for( int v: edges[s] )
            if( visited[v] == -1 ){
                visited[v] = 1;
                Q.push(v);
            }
    }

    return visited;
}

vector<int> Graph::BFS_distances(int start_node){
    vector<int> distances(num_nodes,-1);
    queue<int> Q;

    distances[start_node]++;
    Q.push(start_node);
    while(!Q.empty()){
        int s = Q.front();
        Q.pop();
        for( int v: edges[s] )
            if( distances[v] == -1 ){
                distances[v] = distances[s] + 1;
                Q.push(v);
            }
    }

    return distances;
}

string Graph::BFS_path(int start_node, int finish_node){
    vector<int> paths(num_nodes,-1);
    queue<int> Q;

    paths[start_node] = STOP;
    Q.push(start_node);
    while(!Q.empty()){
        int s = Q.front();
        Q.pop();
        for( int v: edges[s] )
            if( paths[v] == -1 ){
                paths[v] = s;
                Q.push(v);
            }
    }

    //print_vector(paths);

    if( paths[finish_node] == -1)
        return "Unreachable node.\n";
    else{
        string path = to_string(finish_node) + "\n";
        finish_node = paths[finish_node];
        while( finish_node != STOP ){
            path = to_string(finish_node) + " -> " + path;
            finish_node = paths[finish_node];
        }
        return path;
    }
}

void Graph::BFS_components(){
    vector<int> visited(num_nodes,-1);
    int groupID = 0;

    for(int i = 0; i < num_nodes; ++i)
        if( visited[i] == -1 ){
            queue<int> Q;
            list<int> component;

            component.push_back(i);
            visited[i] = 1;
            Q.push(i);
            while(!Q.empty()){
                int s = Q.front();
                Q.pop();
                for( int v: edges[s] )
                    if( visited[v] == -1 ){
                        component.push_back(v);
                        visited[v] = 1;
                        Q.push(v);
                    }
            }

            cout << "Grupo #" << ++groupID << ": ";
            for(int node: component)
                cout << node << " ";
            cout << "\n";
        }
}

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
