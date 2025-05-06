#include <bits/stdc++.h>

using namespace std;

int solve(vector<int> &coins, int V){
    int n = coins.size();
    vector<vector<int>> dp(
        n+1, 
        vector<int>(V+1, INT_MAX)
    );
    
    for(int i = 0; i<=n; i++){
        dp[i][0]=0;
    }
    
    for(int i = 1; i<=n; i++){
        for(int v = 1; v<=V; v++){
            if(coins[i-1] > v){
                dp[i][v] = dp[i-1][v];
            }else{
                if(dp[i][v-coins[i-1]] == INT_MAX){
                    dp[i][v] = dp[i-1][v];
                    continue;
                }
                dp[i][v] = min(
                    dp[i-1][v],
                    dp[i][v-coins[i-1]] + 1
                );
            }
        }
    }
    
    for(int i = 0; i<=n; i++){
        for(int v = 0; v<=V; v++){
            cout << (dp[i][v]==INT_MAX?-1:dp[i][v]) << "\t";
        }
        cout << "\n";
    }
    
    return dp[n][V]==INT_MAX?-1:dp[n][V];
}

int main() {
    vector<int> coins = {2, 5, 10};
    int V = 13;
    
    cout << solve(coins, V) << "\n";

    return 0;
}