#include <bits/stdc++.h>

using namespace std;

void solve(){
    int M, C;
    cin >> M >> C;
    vector<vector<int>> garments;
    for(int c = 0; c<C; c++){
        int K;
        cin >> K;
        vector<int> cat(K);
        for(int &catI: cat){
            cin >> catI;
        }
        garments.push_back(cat);
    }
    
    vector<vector<int>> dp(C+1, vector<int>(M+1, -1));
    dp[0][0] = 0;
    
    int maxSpent=0;
    for(int i=0; i<C; i++){
        for(int j=0; j<=M; j++){
            if(dp[i][j] == -1 || dp[i][j] != i){
                continue;
            }
            for(int garment: garments[i]){
                if(j+garment <= M){
                    dp[i+1][j+garment] = dp[i][j]+1;
                    if(i==C-1){
                        maxSpent = max(maxSpent, j+garment);
                    }
                }
            }
        }
    }
    
    if(dp[C][maxSpent] == -1){
        cout << "no solution\n";
    }else{
        cout << maxSpent << "\n";
    }
    
}

int main() {
    int N;
    cin >> N;
    
    while(N--){
        solve();
    }

    return 0;
}
