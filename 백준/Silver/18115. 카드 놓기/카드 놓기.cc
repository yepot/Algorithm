#include <iostream>
#include <algorithm>
#include <deque>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    deque<int> DQ;
    vector<int> V(n);
    for(int i=0; i<n; i++) cin>>V[i];

    int card = 1;
    for(int i=n-1; i>=0; i--) {
        if(V[i]==1) {
            DQ.push_front(card++);
        }
        else if(V[i]==2) {
            int tmp = DQ.front();
            DQ.pop_front();
            DQ.push_front(card++);
            DQ.push_front(tmp);
        }
        else if(V[i]==3) {
            DQ.push_back(card++);
        }
    }
    
    for(int i=0; i<n; i++) cout << DQ[i] << " ";
}