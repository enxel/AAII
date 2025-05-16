#include <bits/stdc++.h>

using namespace std;

void reconstruct(
    vector<vector<int>> &dp,
    string &s1, string &s2
    ){
    stack<char> sol;
    int i = s1.size();
    int j = s2.size();
    
    while(i>0 && j>0){
        if(dp[i][j] == dp[i][j-1]){
            j--;
        }else if(dp[i][j] == dp[i-1][j]){
            i--;
        }else{
            sol.push(s1[i-1]);
            i--;
            j--;
        }
    }
    
    while(!sol.empty()){
        cout << sol.top();
        sol.pop();
    }
    cout <<"\n";
    
}

void solve(){
    string s1, s2;
    cin >> s1 >> s2;
    
    int l1 = s1.size(), l2 = s2.size();
    
    vector<vector<int>> dp(
        l1+1, 
        vector<int>(
            l2+1,
            0
        )
    );
    
    for(int i=1; i<=l1; i++){
        for(int j=1; j<=l2; j++){
            if(s1[i-1] == s2[j-1]){
                dp[i][j] = dp[i-1][j-1]+1;
            }else{
                dp[i][j] = max(
                    dp[i-1][j],
                    dp[i][j-1]
                    );
            }
        }
    }
    
    cout << dp[l1][l2] << "\n";
    reconstruct(dp, s1, s2);
}

int main() {
    
    solve();

    return 0;
}