#include <bits/stdc++.h>

using namespace std;

#define pii pair<int, int>
#define vpii vector<pii>
#define vi vector<int>

vi dijkstra(vector<vpii> &AL, int start)
{
    vi dists(AL.size(), INT_MAX);
    // Usamos una cola de prioridad para obtener el candidato mas prometedor
    // La cola de prioridad se ordena por el primer elemento del par (costo)
    priority_queue<pii, vpii, greater<pii>> pq;

    pq.emplace(0, start);
    while (!pq.empty())
    {
        pii candidate = pq.top();
        pq.pop();

        cout << "El candidato mas prometedor es (" << candidate.second << ") con un costo de " << candidate.first << "\n";

        if (dists[candidate.second] <= candidate.first)
        {
            cout << "\tYa hay un camino mas corto [" << dists[candidate.second] << "]\n";
            continue;
        }
        dists[candidate.second] = candidate.first;

        for (pii v : AL[candidate.second])
        {
            int dijkstraScore = candidate.first + v.second;
            cout << "\tEl siguiente puede ser (" << v.first << ") con un costo de " << dijkstraScore << "\n";
            pq.emplace(dijkstraScore, v.first);
        }
        cout << "\tNo hay mas candidatos\n";
    }

    return dists;
}

int main()
{

    // Lista de adyacencia del grafo ponderado
    // Cada par indica {destino, costo}
    vector<vpii> AL = {
        {{1, 1}, {2, 4}}, // desde 0
        {{2, 2}, {3, 6}}, // desde 1
        {{3, 3}},         // desde 2
        {}                // desde 3
    };

    // Ejecutamos Dijkstra desde el vertice 0
    vi dists = dijkstra(AL, 0);

    cout << "\nResultados de Dijkstra:\n";
    for (int i = 0; i < AL.size(); i++)
    {
        cout << "(" << i << "): tiene distancia " << dists[i] << "\n";
    }

    return 0;
}