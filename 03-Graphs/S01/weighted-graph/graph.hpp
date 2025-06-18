
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <bits/stdc++.h>
using namespace std;

void print_vector(vector<int> V);

class Graph {
    private:
        int num_nodes;
        vector<vector<pair<int,int>>> edges;

    public:
        Graph(int n);

        void show_adjacencies();

        void add_edge(int a, int b, int w);

        void remove_edge(int a, int b);

        bool find_edge(int a, int b);

        //Optimal Paths
        void Dijkstra(int start_node);

        void Dijkstra_Heap(int start_node);

        string Dijkstra_Reco(int start_node, int end_node);
};


#endif
