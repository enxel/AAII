#include <bits/stdc++.h>

using namespace std;

// Metodo para obtener el minimo elemento de la lista y eliminarlo
pair<int, int> getMin(vector<pair<int, int>> &list)
{
    pair<int, int> minElem = {0, INT_MAX};
    int indexRemove = -1;
    for (int i = 0; i < list.size(); i++)
    {
        if (list[i].second < minElem.second)
        {
            minElem = list[i];
            indexRemove = i;
        }
    }

    cout << "El minimo es (" << minElem.first << ") [distancia " << minElem.second << "]";

    list.erase(list.begin() + indexRemove);
    return minElem;
}

vector<int> dijkstra(
    vector<vector<pair<int, int>>> &AL,
    int start)
{
    // Dist es igual que en BFS
    vector<int> dist(AL.size(), INT_MAX);

    // Se inicializan los candidatos con el vertice start
    vector<pair<int, int>> candidates = {{start, 0}};

    // Mientras haya candidatos...
    while (!candidates.empty())
    {
        // ...obtener el mas prometedor
        pair<int, int> u = getMin(candidates);

        // Si el candidato ya ha sido alcanzado antes, ya se tiene la ruta mas corta, omitir
        if (dist[u.first] != INT_MAX)
        {
            cout << " pero (" << u.first << ") tiene distancia " << dist[u.first] << " [mejor]\n";

            continue;
        }

        cout << " -> puntajes de los vecinos de (" << u.first << ")\n";

        // Se asigna la distancia de la ruta mas corta extraida de los candidatos
        dist[u.first] = u.second;
        for (pair<int, int> v : AL[u.first])
        {
            // Puntaje Dijkstra: distancia hasta (u) + costo de moverse a (v)
            int dijkstraScore = dist[u.first] + v.second;

            cout << "\t(" << v.first << ") esta a " << dijkstraScore << " de (" << start << ")\n";

            // Se guarda la arista candidata en el listado
            candidates.push_back({v.first, dijkstraScore});
        }
        cout << "\tNo hay mas vecinos\n";
    }

    return dist;
}

int main()
{

    // Lista de adyacencia del grafo ponderado
    // Cada par indica {destino, costo}
    vector<vector<pair<int, int>>> AL = {
        {{1, 1}, {2, 4}}, // desde 0
        {{2, 2}, {3, 6}}, // desde 1
        {{3, 3}},         // desde 2
        {}                // desde 3
    };

    // Ejecutamos Dijkstra desde el vertice 0
    vector<int> dists = dijkstra(AL, 0);

    cout << "\nResultados de Dijkstra:\n";
    for (int i = 0; i < AL.size(); i++)
    {
        cout << "(" << i << "): tiene distancia " << dists[i] << "\n";
    }

    return 0;
}