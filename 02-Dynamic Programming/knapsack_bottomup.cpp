#include <bits/stdc++.h>

using namespace std;

int knapsack(int V[], int S[], int n, int C){
    int K[n+1][C+1];
    
    for(int j = 0; j <= C; j++)
        K[0][j] = 0;

    for(int i = 1; i <= n; i++)
        for(int j = 0; j <= C; j++)
            if(S[i] <= j) K[i][j] = max(K[i-1][j], K[i-1][j-S[i]]+V[i]);
            else K[i][j] = K[i-1][j];

    return K[n][C];
}

int main(int argc, char** argv){
    srand(time(NULL));

    int example = atoi(argv[1]);

    int n, C, *V = nullptr, *S = nullptr;
    switch(example){
        case 1:
            n = 4;
            C = 6;
            V = new int[n+1]{-1,3,2,4,4};
            S = new int[n+1]{-1,4,3,2,3};
            break;
        case 2:
            n = 4;
            C = 8;
            V = new int[n+1]{-1,2,4,7,10};
            S = new int[n+1]{-1,1,3,5,7};
            break;
        case 3:
            n = 5;
            C = 10;
            V = new int[n+1]{-1,5,3,2,7,4};
            S = new int[n+1]{-1,2,8,4,2,5};
            break;
        case 4:
            n = 10;
            C = 67;
            V = new int[n+1]{-1,505,352,458,220,354,414,498,545,473,543};
            S = new int[n+1]{-1,23,26,20,18,32,27,29,26,30,27};
            break;
        case 5:
            n = 50;
            C = 850;
            V = new int[n+1]{-1,360, 83, 59, 130, 431, 67, 230, 52, 93, 125, 670, 892, 600, 38, 48, 147,
                             78, 256, 63, 17, 120, 164, 432, 35, 92, 110, 22, 42, 50, 323, 514, 28,
                             87, 73, 78, 15, 26, 78, 210, 36, 85, 189, 274, 43, 33, 10, 19, 389, 276,312};
            S = new int[n+1]{-1,7, 0, 30, 22, 80, 94, 11, 81, 70, 64, 59, 18, 0, 36, 3, 8, 15, 42, 9, 0,
                             42, 47, 52, 32, 26, 48, 55, 6, 29, 84, 2, 4, 18, 56, 7, 29, 93, 44, 71,
                             3, 86, 66, 31, 65, 0, 79, 20, 65, 52, 13};
    }

    cout << knapsack(V, S, n, C) << "\n";

    return 0;
}
