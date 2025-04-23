#include <bits/stdc++.h>

using namespace std;

int coinchange(int V[], int n, int C){
    int K[n+1][C+1];

    for(int i = 0; i <= n; i++)
        K[i][0] = 0;
    
    for(int j = 1; j <= C; j++)
        K[0][j] = INT_MAX;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= C; j++)
            if(V[i] <= j) K[i][j] = min(K[i-1][j], K[i][j-V[i]]+1);
            else K[i][j] = K[i-1][j];

    return K[n][C];
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

    cout << coinchange(V, n, C) << "\n";

    return 0;
}
