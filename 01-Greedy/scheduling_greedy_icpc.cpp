#include <bits/stdc++.h>

#define task pair<int,int>
#define scoredTask pair<float,task>

using namespace std;

int main() {
    
    int n, li, wi;
    cin >> n;
    
    vector<scoredTask> wCs;
    
    for(int i=0; i<n; i++){
        cin >> li >> wi;
        wCs.push_back({
            (wi*1.0f)/(li*1.0f),
            {li, wi}
        });
    }
    
    sort(wCs.rbegin(), wCs.rend());
    
    for(scoredTask st: wCs){
        cout << "Length: " << st.second.first << " - Weight: " << st.second.second << "\n";
    }

    return 0;
}
