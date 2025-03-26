#include <bits/stdc++.h>

using namespace std;

void greedy_solver(tuple<int, int>* A, int n) {
    sort(A, A + n, [](const tuple<int, int>& t1, const tuple<int, int>& t2) {
        double ratio1 = static_cast<double>(get<1>(t1)) / get<0>(t1);
        double ratio2 = static_cast<double>(get<1>(t2)) / get<0>(t2);
        return ratio1 >= ratio2;
    });

    cout << "Optimal Schedule:\n";
    for (int i = 0; i < n; ++i) {
        cout << "Task #" << i+1 << ": (" << get<0>(A[i]) << ", " << get<1>(A[i]) << ")\n";
    }
}

int main(){
	tuple<int,int> tau1[3] = {{1,1},{2,1},{3,1}};
	tuple<int,int> tau2[3] = {{1,3},{2,2},{3,1}};
	tuple<int,int> tau3[4] = {{78,97},{7,18},{100,11},{82,76}};
	tuple<int,int> tau4[5] = {{25,26},{16,45},{24,76},{86,78},{88,54}};

	greedy_solver(tau1,3); cout << "\n=================\n";
	greedy_solver(tau2,3); cout << "\n=================\n";
	greedy_solver(tau3,4); cout << "\n=================\n";
	greedy_solver(tau4,5);

	return 0;
}
