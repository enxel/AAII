#include <bits/stdc++.h>
using namespace std;

int lcs(string S1, string S2){
    int l1 = S1.length();
    int l2 = S2.length();

    int memo[l1+1][l2+1];

    for(int i = 0; i <= l1; i++)
        memo[i][0] = 0;
    for(int j = 1; j <= l2; j++)
        memo[0][j] = 0;
    
    for(int i = 1; i <= l1; i++)
        for(int j = 1; j <= l2; j++)
            if(S1[i-1] == S2[j-1])
                memo[i][j] = 1 + memo[i-1][j-1];
            else
                memo[i][j] = max( memo[i-1][j], memo[i][j-1]);
    
    return memo[l1][l2];
}

int main(int argc, char* argv[]){
    int op = atoi(argv[1]);
    string cad1, cad2;
    
    switch(op){
        case 1:
            cad1 = "AGGTAB";
            cad2 = "GXTXAYB";
            break;
        case 2:
            cad1 = "barcelona";
            cad2 = "arsenal";
            break;
    }

    cout << lcs(cad1, cad2) << "\n";

    return 0;
}