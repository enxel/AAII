#include <bits/stdc++.h>

using namespace std;

int cut_rod(int p[], int n){
    if(n == 0) return 0;
    int q = INT_MIN;
    for(int i = 1; i <= n; i++)
        q = max(q,p[i] + cut_rod(p, n-i));
    return q;
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
