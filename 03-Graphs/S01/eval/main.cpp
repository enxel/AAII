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

    cout << "Listas de adyacencias del Grafo 1:\n";
    G1.show_adjacencies();
    cout << "\nVector de conectividades [Respuesta Ejercicio 1]:\n";
    print_vector(G1.BFS_connectivity(atoi(argv[2]) - ((index_base==0)?0:1)));
    cout << "\nComponentes [Respuesta Ejercicio 3]:\n";
    G1.BFS_components();
    cout << "\nListas de adyacencias del Grafo 1.7:\n";
    G2.show_adjacencies();
    cout << "\nTopological Sort [Respuesta Ejercicio 6]:\n";
    vector<int> topo = G2.TopoSort();
    vector<int> ordered = order_builder(topo);
    if(DAG_checker(ordered, G2.get_edges())) cout << "****** SÍ ES DAG *******\n";
    else cout << "****** NO ES DAG *******\n";
    print_vector(topo);
    //print_vector(ordered);
    cout << "\nStrongly Connected Components (Tarjan) [Respuesta Ejercicio 7]:\n";
    G1.SCCs();
    cout << "\nListas de adyacencias del Grafo 2:\n";
    G3.show_adjacencies();
    cout << "\nDijkstra path lengths [Respuesta Ejercicio 8]:\n";
    G3.Dijkstra_Heap(atoi(argv[3]) - ((index_base==0)?0:1));

    return 0;
}