#include <bits/stdc++.h>
using namespace std;

enum state {Q0, Q1, Q2};

void process(enum state* Q, char c){
    if(*Q == Q2) return;
    switch(*Q){
        case Q0:
            switch(c){
                case '0':
                    *Q = Q2;
                    return;
                case '1':
                    *Q = Q1;
                    return;
            }
        case Q1:
            switch(c){
                case '1': return;
                case '0':
                    *Q = Q2;
                    return;
            }
    }
}

int main(){
    enum state Q = Q0;
    vector<enum state> F;
    F.push_back(Q1);

    string input;
    cin >> input;
    for(int i = 0; i < input.length(); i++)
        process(&Q, input[i]);
    
    if(find(F.begin(), F.end(), Q) != F.end()) cout << "ACCEPTED\n";
    else cout << "REJECTED\n";

    return 0;
}