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
            
            for(int i = 0; i < num_nodes; i++)
                for(int j = 0; j < num_nodes; j++)
                    adjacencies[i][j] = 0;
        }

        void show_adjacencies(){
            for(int i = 0; i < num_nodes; i++){
                cout << "[ ";
                for(int j = 0; j < num_nodes; j++)
                    cout << adjacencies[i][j] << " ";
                cout << "]\n";
            }
        }
};

int main(void){
    Graph G(7);

    G.show_adjacencies();

    return 0;
}