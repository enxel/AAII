#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
        int num_nodes;
        int** adjacencies;

    public:
        Graph(int n){
            num_nodes = n;
            adjacencies = new int*[num_nodes];
            
            for(int i = 0; i < num_nodes; i++)
                adjacencies[i] = new int[num_nodes];
            
            //int adjancencies[num_nodes][num_nodes]
            //A partir de este momento se puede usar
            //la matriz como que si se hubiera declarado
            //normalmente.
            for(int i = 0; i < num_nodes; i++)
                for(int j = 0; j < num_nodes; j++)
                    adjacencies[i][j] = 0;
        }

        void show_adjancencies(){
            for(int i = 0; i < num_nodes; i++){
                cout << "[ ";
                for(int j = 0; j < num_nodes; j++)
                    cout << adjacencies[i][j] << " ";
                cout << "]\n";
            }
        }

        //Se asume grafo dirigido, y sin pesos
        void add_edge(int a, int b){
            adjacencies[a][b] = 1;
        }

        void remove_edge(int a, int b){
            adjacencies[a][b] = 0;
        }

        bool find_edge(int a, int b){
            return adjacencies[a][b] == 1;
        }
};

int main(){
    Graph G(6);

    G.show_adjancencies();
    cout << "\n\n";
    
    G.add_edge(0,1);
    G.add_edge(2,1);
    G.add_edge(2,3);
    G.add_edge(5,2);
    G.add_edge(4,5);
    G.add_edge(2,2); //self-loop
    G.add_edge(4,4); //self-loop

    G.show_adjancencies();

    return 0;
}