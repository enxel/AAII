#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(const vector<vector<int>> &AL, int start)
{
    vector<int> sources(AL.size(), -1);
    queue<int> q;
    
    sources[start] = 0;
    q.push(start);
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (int neighbor : AL[node])
        {
            if (sources[neighbor] == -1)
            {
                sources[neighbor] = node;
                q.push(neighbor);
            }
        }
    }
    return sources;
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
    int end;
    cout << "Ingresar nodo de fin: ";
    cin >> end;

    cout << "\n";

    vector<int> sources = bfs(AL, start);
    cout << "Ruta más corta del inicio al fin:\n";

    if (sources[end] == -1)
    {
        cout << "No existe un camino del nodo " << start << " al nodo " << end << "\n";
    }
    else
    {
        stack<int> path;
        while (end != start)
        {
            path.push(end);
            end = sources[end];
        }

        cout << start;
        while (!path.empty())
        {
            cout << " -> " << path.top();
            path.pop();
        }
        cout << "\n";
    }

    return 0;
}
