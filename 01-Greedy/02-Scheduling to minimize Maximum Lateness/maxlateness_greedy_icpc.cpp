#include <bits/stdc++.h>

#define task pair<int,int>

using namespace std;

int main() {
    
    int n, li, di;
    cin >> n;
    
    vector<task> Ls;
    
    for(int i=0; i<n; i++){
        cin >> li >> di;
        Ls.push_back({di,li});
    }
    
    sort(Ls.begin(), Ls.end());
    
    for(task t: Ls){
        cout << "Length: " << t.second << " - Deadline: " << t.first << "\n";
    }

    return 0;
}
