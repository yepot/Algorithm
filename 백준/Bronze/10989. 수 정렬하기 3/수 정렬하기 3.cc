#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>> n;
    int arr[10001] = {0, };

    int idx;
    for(int i=0; i<n; i++) {
        cin >> idx;
        arr[idx]++;
    }

    for(int i=0; i<=10000; i++) {
        if(arr[i]==0) continue;
        else {
            for(int j=0; j<arr[i]; j++) {
                cout << i << '\n';
            }
        }
    }

}