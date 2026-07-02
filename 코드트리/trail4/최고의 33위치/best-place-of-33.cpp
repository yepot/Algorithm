#include <iostream>
using namespace std;

int n;
bool arr[21][21];

int coin(int x, int y) {
    int cnt = 0;
    for(int i=x-1; i<=x+1; i++) {
        for(int j=y-1; j<=y+1; j++) {
            if(arr[i][j]==1) cnt++;
        }
    }
    return cnt;
}

int main() {
    // Please write your code here.
    int max = 0;

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    for(int i=1; i<n-1; i++) {
        for(int j=1; j<n-1; j++) {
            if(coin(i, j) > max) max = coin(i, j);
        }
    }

    cout << max;

    return 0;
    
}