#include <bits/stdc++.h>

using namespace std;

pair<int,string> coinchange(int V[], int n, int C){
    int K[n+1][C+1];
    string R[n+1][C+1];

    for(int i = 0; i <= n; i++){
        K[i][0] = 0;
        R[i][0] = "";
    }
    
    for(int j = 1; j <= C; j++)
        K[0][j] = INT_MAX;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= C; j++)
            if(V[i] <= j && K[i][j-V[i]]+1 < K[i-1][j]){
                K[i][j] = K[i][j-V[i]]+1;
                R[i][j] = R[i][j-V[i]]+", "+to_string(V[i]);
            }else{
                K[i][j] = K[i-1][j];
                R[i][j] = R[i-1][j];
            }

    return make_pair(K[n][C],R[n][C]);
}

int main(int argc, char** argv){
    srand(time(NULL));

    int example = atoi(argv[1]);

    int n, C, *V = nullptr;
    switch(example){
        case 1:
            n = 3;
            C = 30;
            V = new int[n+1]{-1,5,10,25};
            break;
        case 2:
            n = 4;
            C = 19;
            V = new int[n+1]{-1,1,5,6,9};
            break;
        case 3:

            break;
        case 4:

            break;
        case 5:
        ;
    }

    pair<int,string> results = coinchange(V, n, C);
    cout << "La cantidad mínima de monedas es: " << results.first << "\n";
    cout << "Se obtiene con la siguiente combinación: " << results.second << "\n";
    
    return 0;
}
