#include "graph.hpp"

int main(void){
    Graph G1(4);

    G1.add_edge(0,1);
    G1.add_edge(0,2);
    G1.add_edge(2,1);
    G1.add_edge(2,3);
    G1.add_edge(3,2);
    G1.show_adjacencies();
    print_vector(G1.BFS_connectivity(2));
    print_vector(G1.BFS_distances(2));
    cout << G1.BFS_path(2,1);
    cout << G1.BFS_path(2,0);

    cout << "\n------------------\n\n";

    Graph G2(5);
    G2.add_edge(0,1);
    G2.add_edge(1,0);
    G2.add_edge(1,2);
    G2.add_edge(2,1);
    G2.add_edge(0,2);
    G2.add_edge(2,0);
    G2.add_edge(0,3);
    G2.add_edge(3,0);
    G2.add_edge(3,4);
    G2.add_edge(4,3);
    G2.show_adjacencies();
    print_vector(G2.BFS_connectivity(4));
    print_vector(G2.BFS_distances(4));
    cout << G2.BFS_path(4,2);
    cout << G2.BFS_path(4,0);

    cout << "\n------------------\n\n";

    Graph G3(6);
    G3.add_edge(0,1);
    G3.add_edge(1,0);
    G3.add_edge(1,2);
    G3.add_edge(2,1);
    G3.add_edge(3,4);
    G3.add_edge(4,3);
    G3.add_edge(3,5);
    G3.add_edge(5,3);
    G3.add_edge(4,5);
    G3.add_edge(5,4);
    G3.BFS_components();

    cout << "\n------------------\n\n";

    Graph G4(8);
    G4.add_edge(1,2);
    G4.add_edge(2,0);
    G4.add_edge(1,0);
    G4.add_edge(1,3);
    G4.add_edge(5,1);
    G4.add_edge(4,1);
    G4.add_edge(0,5);
    G4.add_edge(0,4);
    G4.add_edge(5,4);
    G4.add_edge(3,7);
    G4.add_edge(5,7);
    G4.add_edge(3,6);
    G4.add_edge(6,4);
    G4.add_edge(7,6);
    print_vector(G4.DFS(0));

    cout << "\n------------------\n\n";

    Graph G5(7);
    G5.add_edge(0,1);
    G5.add_edge(0,2);
    G5.add_edge(1,2);
    G5.add_edge(1,5);
    G5.add_edge(2,3);
    G5.add_edge(5,3);
    G5.add_edge(5,4);
    G5.add_edge(6,1);
    G5.add_edge(6,5);
    print_vector(G5.TopoSort());

    cout << "\n------------------\n\n";

    Graph G6(11);
    G6.add_edge(0,1);
    G6.add_edge(0,3);
    G6.add_edge(1,2);
    G6.add_edge(1,4);
    G6.add_edge(2,0);
    G6.add_edge(2,6);
    G6.add_edge(3,2);
    G6.add_edge(4,5);
    G6.add_edge(4,6);
    G6.add_edge(5,6);
    G6.add_edge(5,7);
    G6.add_edge(5,8);
    G6.add_edge(5,9);
    G6.add_edge(6,4);
    G6.add_edge(7,9);
    G6.add_edge(8,9);
    G6.add_edge(9,8);
    G6.SCCs();

    return 0;
}
