#include <bits/stdc++.h>

using namespace std;

int cut_rod_aux(int p[], int n, int r[]){
    if(r[n] >= 0) return r[n];
    int q;
    if(n == 0) q = 0;
    else{
        q = INT_MIN;
        for(int i = 1; i <= n; i++)
            q = max(q,p[i] + cut_rod_aux(p, n-i,r));
    }
    r[n] = q;
    return q;
}

int cut_rod(int p[], int n){
    int r[n+1];
    for(int i = 0; i <= n; i++)
        r[i] = INT_MIN;
    return cut_rod_aux(p, n, r);
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

    cout << cut_rod(p,n) << "\n";

    delete[] p;

    return 0;
}
