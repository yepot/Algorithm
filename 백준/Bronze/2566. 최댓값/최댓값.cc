#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int arr[82][82] = {};
    int max = -1;
    int x, y;
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            cin >> arr[i][j];
            if(arr[i][j]>max) {
                max = arr[i][j];
                x = i+1;
                y = j+1;
            }
        }
    }
    cout << max << '\n' << x << ' ' << y;
}
