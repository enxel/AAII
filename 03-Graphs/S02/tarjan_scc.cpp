#include <bits/stdc++.h>

using namespace std;

class Tarjan { // Clase Tarjan para encontrar componentes fuertemente conexos (SCC)
private:
    vector<int> disc;
    vector<int> low;
    
    stack<int> st;
    vector<bool> inStack;
    
    int sccCount;
    int id;
    
    void dfs(vector<vector<int>> &adj, int u){
        disc[u] = low[u] = id++; // Inicializamos el tiempo de descubrimiento y low-link
        st.push(u);
        inStack[u] = true;
        for(int v: adj[u]){
            if(disc[v] == -1){ // Si no ha sido visitado, realizamos DFS
                dfs(adj, v);
            }
            if(inStack[v]){ // Si está en la pila, es parte del ciclo
                low[u] = min(low[u], low[v]); // Actualizamos el low-link al mínimo
            }
        }
        
        if(disc[u] == low[u]){ // Se dio un ciclo, se encontró un SCC
            while(true){
                int compare = st.top();
                st.pop();
                inStack[compare] = false;
                low[compare] = u; // Asignar el líder del SCC
                if(compare == u){ // Si es el líder, salimos del ciclo
                    break;
                }
            }
            sccCount++; // Incrementamos el contador de SCCs
        }
    }
public:
    pair<int, vector<int>> scc(vector<vector<int>> &adj) {
        disc.assign(adj.size(), -1); // Inicializamos el tiempo de descubrimiento, -1 significa no visitado
        low.assign(adj.size(), -1); // Inicializamos el low-link, -1 significa no visitado
        
        while(!st.empty()){ // Limpiamos la pila antes de comenzar
            st.pop();
        }
        inStack.assign(adj.size(), false);
        
        sccCount = 0; // Contador de componentes fuertemente conexos
        id = 0; // Inicializamos el identificador de tiempo de descubrimiento
        
        for(int u=0; u<adj.size(); u++){ // Iteramos sobre todos los nodos
            if(disc[u] == -1){ // Si no ha sido visitado, iniciamos DFS
                dfs(adj, u);
            }
        }
        
        return {sccCount, low}; // Retornamos el número de SCCs y el vector de líderes de SCC
    }
};

int main() {
    Tarjan ta = Tarjan();
    vector<vector<int>> AL = {
        {1},
        {2},
        {0},
        {1,2,5},
        {2,6},
        {3,4},
        {4},
        {5,6}
    };
    
    pair<int, vector<int>> tarjanSolution = ta.scc(AL);
    
    cout << tarjanSolution.first << "\n";
    for(int i = 0; i<AL.size(); i++){
        cout << i << " -> SCC Head " << tarjanSolution.second[i] << "\n";
    }

    return 0;
}