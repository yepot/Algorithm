#include <iostream>
using namespace std;

int n;
int arr[2200][2200];
int cnt[3];

bool check(int a, int b, int n) {
    for(int i=a; i<a+n; i++) {
        for(int j=b; j<b+n; j++) {
            if(arr[i][j]!=arr[a][b]) {
                return false;
            }
        }
    }
    return true;
}

void func(int a, int b, int n) {
    if(check(a, b, n)) {
        cnt[arr[a][b]+1]++;
        return;
    }
    int k = n/3;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            func(a+i*k, b+j*k, k);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }
    
    func(0, 0, n);
    for(int i=0; i<3; i++) {
        cout << cnt[i] <<'\n';
    }
}