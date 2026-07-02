#include <iostream>
using namespace std;

int main() {
    // Please write your code here.
    int m, n;
    cin >> n >> m;
    int arr[101][101];
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    if(m == 1) {
        cout << 2*n;
        return 0;
    }

    int happy = 0;

    for(int i=0; i<n; i++) {
        int cnt = 1;
        for(int j=1; j<n; j++) {
            if(arr[i][j] == arr[i][j-1]) cnt++;
            else cnt = 1;
        
            if(cnt >= m) {
                happy++;
                break;
            }
        }
    }

    for(int i=0; i<n; i++) {
        int cnt = 1;
        for(int j=1; j<n; j++) {
            if(arr[j-1][i] == arr[j][i]) cnt++;
            else cnt = 1;

            if(cnt >= m) {
                happy++;
                break;
            }
        }
    }

    cout << happy;

    return 0;
}