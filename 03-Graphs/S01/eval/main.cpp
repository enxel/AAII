#include "../graph.hpp"

int main(int argc, char** argv){
    int N, s, v, w, index_base = atoi(argv[1]);
    string entry;

    cin >> N;
    //cout << N << "\n";
    Graph G1(N);

    getline(cin, entry);
    for(int i = 0; i < N; i++){
        getline(cin, entry);
        //cout << "ENTRY: " << entry << "\n";
        stringstream ss(entry);
        string item;
        getline(ss, item, ' ');
        //cout << "ITEM: " << item << "\n";
        s = stoi(item) - ((index_base==0)?0:1);
        //cout << "S: " << s << "\n";
        while(getline(ss, item, ' ')){
            v = stoi(item) - ((index_base==0)?0:1);
            //cout << "S,V: " << s << " " << v << "\n";
            G1.add_edge(s, v);
        }
    }

    cin >> N;
    //cout << N << "\n";
    Graph G2(N);

    getline(cin, entry);
    for(int i = 0; i < N; i++){
        getline(cin, entry);
        //cout << "ENTRY: " << entry << "\n";
        stringstream ss(entry);
        string item;
        getline(ss, item, ' ');
        //cout << "ITEM: " << item << "\n";
        s = stoi(item) - ((index_base==0)?0:1);
        //cout << "S: " << s << "\n";
        while(getline(ss, item, ' ')){
            v = stoi(item) - ((index_base==0)?0:1);
            //cout << "S,V: " << s << " " << v << "\n";
            G2.add_edge(s, v);
        }
    }

    cin >> N;
    //cout << N << "\n";
    WeightedGraph G3(N);

    getline(cin, entry);
    for(int i = 0; i < N; i++){
        getline(cin, entry);
        //cout << "ENTRY: " << entry << "\n";
        stringstream ss(entry);
        string item;
        getline(ss, item, ' ');
        //cout << "ITEM: " << item << "\n";
        s = stoi(item) - ((index_base==0)?0:1);
        //cout << "S: " << s << "\n";
        while(getline(ss, item, ' ')){
            v = stoi(item) - ((index_base==0)?0:1);
            getline(ss, item, ' ');
            w = stoi(item) - ((index_base==0)?0:1);
            //cout << "S,V,W: " << s << " " << v << " " << w << \n";
            G3.add_edge(s, v, w);
        }
    }

    G1.show_adjacencies();
    print_vector(G1.BFS_connectivity(atoi(argv[2])));
    G1.BFS_components();
    G1.SCCs();

    G2.show_adjacencies();
    print_vector(G2.TopoSort());

    G3.show_adjacencies();
    G3.Dijkstra_Heap(atoi(argv[3]));

    return 0;
}