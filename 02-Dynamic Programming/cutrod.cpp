#include <bits/stdc++.h>

using namespace std;

int cut_rod(int p[], int n){
    if(n == 0) return 0;
    int q = INT_MIN;
    for(int i = 0; i < n; i++)
        q = max(q,p[i] + cut_rod(p, n-(i+1)));
    return q;
}

int main(int argc, char** argv){
    srand(time(NULL));

    //int p[10] = {1,5,8,9,10,17,17,20,24,30};
    
    int p[50] = {};
    for(int i = 0; i < 50; i++)
        p[i] = rand() % 100 + 1;
    
    int n = atoi(argv[1]);

    cout << cut_rod(p,n) << "\n";

    return 0;
}
