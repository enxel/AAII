#include <bits/stdc++.h>

using namespace std;

void dfs_topo(
    map<string, vector<string>> &AL, 
    string u, 
    map<string, bool> &visited, 
    map<string, int> &orders, 
    int &currLabel
){
    visited[u] = true;
    
    for(auto v: AL[u]){
        if(visited[v]){
            continue;
        }
        dfs_topo(AL, v, visited, orders, currLabel);
    }
    
    orders[u] = currLabel--;
}

map<string, int> topo_sort(
    map<string, vector<string>> &AL
){
    map<string, int> orders;
    map<string, bool> visited;
    
    int currLabel = AL.size();
    
    cout << "Orden de las claves recorridas:\n";
    cout << "Al usar map estas se recorren en orden alfabetico:\n";
    for(auto mapPair: AL){
        cout << "\t" << mapPair.first << " -> ";
        if(visited[mapPair.first]){
            cout << "ya visitado\n";
            continue;
        }
        cout << "primera vez\n";
        dfs_topo(AL, mapPair.first, visited, orders, currLabel);
    }
    return orders;
}

int main() {
    // Estamos usando map, por lo que las claves se ordenan alfabeticamente.
    map<string, vector<string>> AL = {
        { "Introduction to Programming",  { "Data Structures" } },
        { "Discrete Mathematics",         { "Algorithms" } },
        { "Data Structures",              { "Algorithms", "Database Systems", "Software Engineering" } },
        { "Computer Architecture",        { "Operating Systems" } },
        { "Algorithms",                   { "Operating Systems" } },
        { "Operating Systems",            { "Networking Fundamentals", "Cybersecurity" } },
        { "Database Systems",             { } },
        { "Networking Fundamentals",      { "Cybersecurity", "Cloud Computing" } },
        { "Software Engineering",         { "Human-Computer Interaction", "Capstone Project" } },
        { "Web Development",              { "Software Engineering" } },
        { "Human-Computer Interaction",   { } },
        { "Cybersecurity",                { "Capstone Project" } },
        { "Cloud Computing",              { "Capstone Project" } },
        { "Professional Ethics",          { "Capstone Project" } },
        { "Capstone Project",             { } }
    };
    
    map<string, int> orders = topo_sort(AL);
    set<pair<int, string>> ordered_list;
    
    for(auto &[k, v]: orders){
        ordered_list.insert({v, k});
    }
    
    cout << "\nOrden topologico:\n";
    for (auto val: ordered_list){
        cout << val.first << ")\t" << val.second << "\n";
    }

    return 0;
}