#include <bits/stdc++.h>

using namespace std;

#define pii pair<int,int>
#define vpii vector<pii>

class Candidate{
public:
    int node;
    int cost;

    Candidate(int node, int cost){
        this->node = node;
        this->cost = cost;
    }
};

Candidate minVal(vector<Candidate> &candidates){
    int minIndex = -1;
    
    Candidate minCand = Candidate(-1, INT_MAX);
    for(int i=0; i<candidates.size(); i++){
        if(candidates[i].cost < minCand.cost){
            minCand = candidates[i];
            minIndex = i;
        }
    }
    
    candidates.erase(candidates.begin() + minIndex);
    return minCand;
}

vector<int> dijkstra(vector<vpii> &AL, int start){
    vector<Candidate> candidates;
    candidates.push_back(Candidate(start, 0));
    vector<int> dists(AL.size(), INT_MAX);
    
    while(!candidates.empty()){
        Candidate u = minVal(candidates);
        if(u.cost >= dists[u.node]){
            continue;
        }
        dists[u.node] = u.cost;
        
        for(auto v: AL[u.node]){
            int dijkstraScore = dists[u.node] + v.second;
            candidates.push_back(
                Candidate(v.first, dijkstraScore)
            );
        }
    }
    return dists;
};

int main() {
    /*
    vector<Candidate> candidates;
    candidates.push_back(Candidate(1,5));
    candidates.push_back(Candidate(2,2));
    candidates.push_back(Candidate(3,15));
    candidates.push_back(Candidate(4,7));
    
    Candidate minValue = minVal(candidates);
    
    cout << minValue.node << " " << minValue.cost << "\n------\n";
    
    for(Candidate c: candidates){
        cout << c.node << " " << c.cost << "\n";
    }
    */
    
    vector<vpii> AL = {
        {{1,1}, {2,4}}, // 0
        {{2,2}, {3,6}}, // 1
        {{3,3}},        // 2
        {}              // 3
    };
    
    vector<int> dists = dijkstra(AL, 0);
    
    for(int i=0; i<AL.size(); i++){
        cout << i << " costs " << dists[i] << "\n";
    }

    return 0;
}