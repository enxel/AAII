#include <bits/stdc++.h>

using namespace std;

int main(void){
    int T;

    cin >> T;

    for(int i = 0; i < T; i++){
        int M,C;
        cin >> M >> C;
        vector<vector<int>> garments;

        for(int j = 0; j < C; j++){
            int K;
            cin >> K;

            vector<int> modelos;

            for(int p = 0; p < K; p++){
                int m;
                cin >> m;
                modelos.push_back(m);
            }

            garments.push_back(modelos);
        }

        /*
        for(int i = 0; i < C; i++){
            cout << "[";
            for(int j = 0; j < garments.at(i).size(); j++)
                cout << garments.at(i).at(j) << " ";
            cout << "]\n";
        }
        */

        int memo[C+1][M+1];

        for(int i = 0; i <= M; i++)
            memo[0][i] = 0;
        
        for(int i = 1; i <= C; i++)
            for(int j = 0; j <= M; j++)
                memo[i][j] = INT_MIN;
        
        for(int i = 1; i <=C; i++)
            for(int j = 0; j <= M; j++)
                for(int k = 0; k < garments.at(i-1).size(); k++){
                    int N = garments.at(i-1).at(k);
                    if( N <= j && memo[i-1][j-N] != INT_MIN)
                        memo[i][j] = max(memo[i][j],memo[i-1][j-N]+N);
                }
        
        /*
        for(int i = 1; i <=C; i++){
            cout << "[ ";
            for(int j = 0; j <= M; j++){
                cout << memo[i][j] << " ";
            }
            cout << "]\n";
        }
        */   

        if(memo[C][M] == INT_MIN) cout << "no solution\n";
        else cout << memo[C][M] << "\n";
    }

    return 0;
}