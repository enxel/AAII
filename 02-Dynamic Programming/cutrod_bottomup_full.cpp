#include <bits/stdc++.h>

using namespace std;

string reconstruct_cuts(int s[], int n){
    string cuts = "El primer pedazo se corta a los " + to_string(s[n]) + "dm\n";
    
    int pos = n-s[n];
    while(pos > 0){
        cuts += "El siguiente pedazo se corta a los " + to_string(s[pos]) + "dm\n";
        pos -= s[pos];
    }
    
    return cuts;
}

pair<int,string> cut_rod(int p[], int n){
    int r[n+1],s[n+1];
    r[0] = 0;
    s[0] = 0;
    for(int j = 1; j <= n; j++){
        int q = INT_MIN;
        for(int i = 1; i <= j; i++)
            if(p[i] + r[j-i] > q){
                q = p[i] + r[j-i];
                s[j] = i;
            }
        r[j] = q;
    }

    string cuts = reconstruct_cuts(s,n);
    return make_pair(r[n],cuts);
}

int main(int argc, char** argv){
    srand(time(NULL));

    int n = atoi(argv[1]);
    int mode = atoi(argv[2]);

    int* p = nullptr;
    if(mode == 1){
        p = new int[11]{-1,1,5,8,9,10,17,17,20,24,30};
    }else{
        p = new int[51];
        p[0] = -1;
        for(int i = 1; i <= 50; i++)
            p[i] = rand() % 100 + 1;
    }

    pair<int,string> results = cut_rod(p,n);
    cout << "La ganancia máxima es: $" << results.first << "\n";
    cout << "Se obtiene de la siguiente forma:\n";
    cout << results.second;

    return 0;
}
