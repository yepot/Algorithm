#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    
    vector<int> A(n);;
    vector<int> B(n);

    int sum = 0;

    for(int i=0; i<n; i++) cin >> A[i];
    for(int i=0; i<n; i++) cin >> B[i];

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), less<int>());

    for(int i=0; i<n; i++) sum+=A[i]*B[i];
    cout << sum << '\n';

}