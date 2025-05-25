#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(const vector<vector<int>> &AL, int start)
{
    vector<int> layers(AL.size(), -1);
    queue<int> q;
    q.push(start);
    layers[start] = 0;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbor : AL[node])
        {
            if (layers[neighbor] == -1)
            {
                layers[neighbor] = layers[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return layers;
}

int main()
{
    int nNodes;
    cout << "Cantidad de nodos: ";
    cin >> nNodes;
    cout << "\n";

    vector<vector<int>> AL(nNodes, vector<int>());

    int a, b;
    cout << "Ingresar arista (a b): ";
    cin >> a >> b;

    while (a != -1 && b != -1)
    {
        AL[a].push_back(b);
        cout << "Ingresar arista (a b): ";
        cin >> a >> b;
    }

    cout << "\n";

    int start;
    cout << "Ingresar nodo de inicio: ";
    cin >> start;

    cout << "\n";

    vector<int> layers = bfs(AL, start);
    cout << "Distribución de capas:\n";
    for (int i = 0; i < nNodes; i++)
    {
        cout << i << " -> " << layers[i] << "\n";
    }

    return 0;
}