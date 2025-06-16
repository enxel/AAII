
#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <bits/stdc++.h>
#define STOP -100
using namespace std;

void print_vector(vector<int> V);

class Graph{
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

        //BFS
        vector<int> BFS_connectivity(int start_node);

        vector<int> BFS_distances(int start_node);

        string BFS_path(int start_node, int finish_node);

        void BFS_components();

        //DFS
        vector<int> DFS(int start_node);

        vector<int> TopoSort();

        void SCCs();

        //Optimal paths
        int Dijkstra(int start_node);
};


#endif
