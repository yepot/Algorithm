#include <iostream>
using namespace std;

int n, m;
int arr[21][21];
int answer = -1;

// 직사각형 순회 (왼쪽 위, 오른쪽 아래)
int rectangle(int x1, int y1, int x2, int y2) {

    for(int i=x1; i<=x2; i++) {
        for(int j=y1; j<=y2; j++) {
            if(arr[i][j] <= 0) return 0;
        }
    }
    return (x2-x1+1)*(y2-y1+1);

}

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> arr[i][j];
        }
    }

    for(int x1=0; x1<n; x1++) {
        for(int y1=0; y1<m; y1++) {
            if(arr[x1][y1] <= 0) continue;
            for(int x2=x1; x2<n; x2++) {
                for(int y2=y1; y2<m; y2++) {
                    if(arr[x2][y2] <= 0) continue;
                    if(rectangle(x1, y1, x2, y2) > answer) {
                        answer = rectangle(x1, y1, x2, y2);
                    }
                }   
            }
        }
    }

    cout << answer;
    return 0;
}