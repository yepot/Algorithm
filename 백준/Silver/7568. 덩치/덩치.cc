#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    vector<pair<int, int>> V(n);
    int rank;
    for(int i=0; i<n; i++) {
        cin >> V[i].first >> V[i].second;
    }

    for(int i=0; i<n; i++) {
        rank = 1;
        for(int j=0; j<n; j++) {
            if(V[i].first<V[j].first && V[i].second<V[j].second) {
                rank++;
            }
        }
        cout << rank << ' ';
    }

}
