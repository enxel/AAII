#include "graph.hpp"
#define STOP -100

void print_vector(vector<int> V){
    for(int i = 0; i < V.size(); ++i)
        cout << V[i] << " ";
    cout << "\n";
}

void Graph::Dijkstra(int s){
    vector<int> visited(num_nodes, -1);
    vector<int> dist(num_nodes, INT_MAX);
    int cont_visited = 0;

    dist[s] = 0;
    while(cont_visited != num_nodes){
        int min_index = -1;
        int min_dist = INT_MAX;
        for(int i = 0; i < num_nodes; ++i){
            if( dist[i] != INT_MAX && visited[i] == -1 && dist[i] < min_dist ){
                min_index = i;
                min_dist = dist[i];
            }
        }
        for(pair<int,int> v: edges[min_index]){
            int candidate = min_dist + v.second;
            if( candidate < dist[v.first] )
                dist[v.first] = candidate;
        }
        visited[min_index] = 1;
        ++cont_visited;
    }

    print_vector(dist);
}

void Graph::Dijkstra_Heap(int s){
    vector<int> dist(num_nodes, INT_MAX);    
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > min_heap;

    dist[s] = 0;
    min_heap.push(make_pair(dist[s],s));
    while(!min_heap.empty()){
        int node = min_heap.top().second;
        int distance = min_heap.top().first;
        min_heap.pop();

        for(pair<int,int> v: edges[node]){
            int candidate = distance + v.second;
            if( candidate < dist[v.first] ){
                dist[v.first] = candidate;
                min_heap.push(make_pair(candidate, v.first));
            }
        }
    }

    print_vector(dist);
}

string Graph::Dijkstra_Reco(int s, int e){
    vector<int> prev(num_nodes, STOP);
    vector<int> dist(num_nodes, INT_MAX);    
    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > min_heap;

    dist[s] = 0;
    min_heap.push(make_pair(dist[s],s));
    while(!min_heap.empty()){
        int node = min_heap.top().second;
        int distance = min_heap.top().first;
        min_heap.pop();

        for(pair<int,int> v: edges[node]){
            int candidate = distance + v.second;
            if( candidate < dist[v.first] ){
                dist[v.first] = candidate;
                prev[v.first] = node;
                min_heap.push(make_pair(candidate, v.first));
            }
        }
    }

    //print_vector(prev);

    if( prev[e] == STOP)
        return "Unreachable node.\n";
    else{
        string path = to_string(e) + "\n";
        e = prev[e];
        while( e != STOP ){
            path = to_string(e) + " -> " + path;
            e = prev[e];
        }
        return path;
    }
}
