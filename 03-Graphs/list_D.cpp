#include <bits/stdc++.h>
//#include <algorithm>
using namespace std;

class Graph{
    private:
        int num_nodes;
        vector<vector<int>> edges;

    public:
        Graph(int n){
            num_nodes = n;
            for(int i = 0; i < num_nodes; i++){
                vector<int> temp;
                edges.push_back(temp);
            }
        }

        void show_adjacencies(){
            for(int i = 0; i < edges.size(); i++){
                cout << "[ ";
                for(int j = 0; j < edges[i].size(); j++)
                    cout << edges[i][j] << " ";
                cout << "]\n";
            }
        }

        //Se asume grafo no dirigido, y sin pesos
        void add_edge(int a, int b){
            edges[a].push_back(b);
        }

        void remove_edge(int a, int b){
            edges[a].erase( find( edges[a].begin(), edges[a].end(), b ) );
        }

        bool find_edge(int a, int b){
            return find( edges[a].begin(), edges[a].end(), b ) != edges[a].end();
        }
};

int main(){
    Graph G(6);

    G.show_adjacencies();
    cout << "\n\n";
    
    G.add_edge(0,1);
    G.add_edge(1,2);
    G.add_edge(2,3);
    G.add_edge(5,2);
    G.add_edge(5,4);
    G.add_edge(2,2); //self-loop
    G.add_edge(4,4); //self-loop

    G.show_adjacencies();

    return 0;
}