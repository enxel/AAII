#include "graph.hpp"

WeightedGraph::WeightedGraph(int n){
    num_nodes = n;
    for(int i = 0; i < num_nodes; i++){
        vector<pair<int,int>> temp;
        edges.push_back(temp);
    }
}

void WeightedGraph::show_adjacencies(){
    for(int i = 0; i < edges.size(); i++){
        cout << "[ ";
        for(int j = 0; j < edges[i].size(); j++)
            cout << "( " << edges[i][j].first << ", " << edges[i][j].second << " ) ";
        cout << "]\n";
    }
}

void WeightedGraph::add_edge(int a, int b, int w){
    edges[a].push_back(make_pair(b,w));
}

void WeightedGraph::remove_edge(int a, int b){
    edges[a].erase( find_if( edges[a].begin(), edges[a].end(), [b] (pair<int,int> p) { return p.first == b; } )  );
}

bool WeightedGraph::find_edge(int a, int b){
    return find_if( edges[a].begin(), edges[a].end(), [b] (pair<int,int> p) { return p.first == b; } ) != edges[a].end();
}
