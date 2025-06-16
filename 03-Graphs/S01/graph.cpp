#include "graph.hpp"

Graph::Graph(int n){
    num_nodes = n;
    for(int i = 0; i < num_nodes; i++){
        vector<int> temp;
        edges.push_back(temp);
    }
}

void Graph::show_adjacencies(){
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
