#include "graph.hpp"

int main(void){
    Graph G1(4);

    G1.add_edge(0,1,4);
    G1.add_edge(0,2,1);
    G1.add_edge(1,3,1);
    G1.add_edge(2,1,2);
    G1.add_edge(2,3,5);
    // G1.show_adjacencies();
    // cout << G1.find_edge(2,1) << "\n";
    // cout << G1.find_edge(2,0) << "\n";
    // G1.remove_edge(2,1);
    // G1.show_adjacencies();
    G1.Dijkstra(0);
    G1.Dijkstra_Heap(0);
    cout << G1.Dijkstra_Reco(0,3) << "\n";

    cout << "------------------\n\n";

    Graph G2(11);

    G2.add_edge(0,10,3);
    G2.add_edge(1,0,5);
    G2.add_edge(1,6,1);
    G2.add_edge(2,1,4);
    G2.add_edge(2,3,1);
    G2.add_edge(3,4,1);
    G2.add_edge(3,6,4);
    G2.add_edge(4,1,1);
    G2.add_edge(4,5,5);
    G2.add_edge(5,7,2);
    G2.add_edge(5,8,3);
    G2.add_edge(6,5,3);
    G2.add_edge(6,7,1);
    G2.add_edge(7,0,2);
    G2.add_edge(7,8,1);
    G2.add_edge(7,10,5);
    G2.add_edge(8,9,1);
    G2.add_edge(8,10,3);
    G2.add_edge(9,10,1);
    G2.Dijkstra(2);
    G2.Dijkstra_Heap(2);
    cout << G2.Dijkstra_Reco(2,10) << "\n";

    return 0;
}
