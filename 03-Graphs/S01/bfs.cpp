#include "graph.hpp"

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