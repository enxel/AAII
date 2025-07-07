#include "graph.hpp"

void print_vector(vector<int> V){
    for(int i = 0; i < V.size(); ++i)
        cout << V[i] << " ";
    cout << "\n";
}

vector<int> order_builder(vector<int> A){
    vector<int> T(A.size());

    for(int i = 0; i < A.size(); i++)
        T[A[i]-1] = i;

    return T;
}

bool DAG_checker(vector<int> T, vector<vector<int>> edges){
    for(int i = 0; i < T.size(); i++)
        for(int v: edges[T[i]])
            for(int j = 0; j < i; j++)
                if(v == T[j]) return false;

    return true;
}
