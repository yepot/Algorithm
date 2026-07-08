#include <iostream>
using namespace std;

int n, m;
int arr[21][21];
int answer = 0;

int countGold(int k, int x, int y) {
    int cnt = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(abs(i-x) + abs(j-y) <= k) { // 마름모 범위 판단하는 법!
                if(arr[i][j] == 1) cnt++;
            }
        }
    }

    return cnt;
}

int main() {
    // Please write your code here.
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    for (int k=0; k<=2*n; k++) {
        int cost = k*k + (k+1)*(k+1);
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                if (countGold(k, i, j)*m >= cost) {
                    answer = max(answer, countGold(k, i, j));
                }
            }
        }
    }

    cout << answer;

    return 0;
}