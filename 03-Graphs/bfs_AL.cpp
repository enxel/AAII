#include <bits/stdc++.h>

using namespace std;

vector<bool> bfs(const vector<vector<int>> &AL, int start)
{
    vector<bool> visited(AL.size(), false);
    queue<int> q;
    q.push(start);
    visited[start] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbor : AL[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return visited;
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

    vector<bool> layers = bfs(AL, start);
    cout << "Nodos con conexión al nodo de inicio:\n";
    for (int i = 0; i < nNodes; i++)
    {
        cout << i << " -> " << (layers[i] ? "true" : "false") << "\n";
    }

    return 0;
}