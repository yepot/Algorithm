#include <iostream>
using namespace std;

int n, m;
int arr[201][201];

int block4(int x, int y) {
    int min = 1001;
    int sum = 0;
    for(int i=x; i<=x+1; i++) {
        for(int j=y; j<=y+1; j++) {
            sum += arr[i][j];
            if(arr[i][j] < min) min = arr[i][j];
        }
    }
    return sum-min;
}

int block3X(int x, int y) {
    int sum = 0;
    for(int i=y; i<y+3; i++) {
        sum += arr[x][i];
    }
    return sum;
}

int block3Y(int x, int y) {
    int sum = 0;
    for(int i=x; i<x+3; i++) {
        sum += arr[i][y];
    }
    return sum;
}

int main() {
    // Please write your code here.
    // 4칸에서 하나 빼자..

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    int max = 0;

    // 4칸
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<m-1; j++) {
            if(block4(i, j) > max) max = block4(i, j);
        }
    }

    // 3칸 가로
    for(int i=0; i<n; i++) {
        for(int j=0; j<m-2; j++) {
            if(block3X(i, j) > max) max = block3X(i, j);
        }
    }

    // 3칸 세로
    for(int i=0; i<n-2; i++) {
        for(int j=0; j<m; j++) {
            if(block3Y(i, j) > max) max = block3Y(i, j);
        }
    }

    cout << max;

    return 0;
}