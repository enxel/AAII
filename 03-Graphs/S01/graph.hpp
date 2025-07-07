
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <bits/stdc++.h>
#define STOP -100
using namespace std;

void print_vector(vector<int> V);
vector<int> order_builder(vector<int> A);
bool DAG_checker(vector<int> T, vector<vector<int>> edges);

class Graph {
    private:
        int num_nodes;
        vector<vector<int>> edges;

        void DFS_aux(vector<int>* visited, int node, int* index);

        void DFS_Topo(vector<int>* visited, vector<int>* f, int node, int* currLabel);

        void SCC_aux(int node, vector<int>* disc, vector<int>* low, stack<int>* S, vector<bool>* stackMember, int* time, int* index);

    public:
        Graph(int n);

        void show_adjacencies();

        void add_edge(int a, int b);

        void remove_edge(int a, int b);

        bool find_edge(int a, int b);

        vector<vector<int>> get_edges();

        //BFS
        vector<int> BFS_connectivity(int start_node);

        vector<int> BFS_distances(int start_node);

        string BFS_path(int start_node, int finish_node);

        void BFS_components();

        //DFS
        vector<int> DFS_iterative(int start_node);

        vector<int> DFS(int start_node);

        vector<int> TopoSort();

        void SCCs();
};

class WeightedGraph {
    private:
        int num_nodes;
        vector<vector<pair<int,int>>> edges;

    public:
        WeightedGraph(int n);

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
